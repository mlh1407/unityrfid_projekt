using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RFIDReader : MonoBehaviour {

	public string gt;
	public string[] ids;
	public GameObject[] gos;

	void Start()
	{
//gt = GetComponent<GUIText>();
	}

	void Update()
	{
		foreach (char c in Input.inputString)
		{
			if ((c == '\n') || (c == '\r')) // enter/return
			{
				print("UID: " + gt);
				gt = "";
			}
			else
			{
				gt += c;
			}
		}
	}
}
