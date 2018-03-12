using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RFIDReader : MonoBehaviour {

	public string gt;
	public string[] ids;
	public GameObject[] gos;
	public int[] states;

	void Start()
	{
//gt = GetComponent<GUIText>();
		off();
	}

	void Update()
	{
		foreach (char c in Input.inputString)
		{
			if ((c == '\n') || (c == '\r')) // enter/return
			{
				print("UID: " + gt);
				if(isiton()){
					
					off ();
				}
				for (int i = 0; i < 2; i++) {
					if(gt==ids[i] && states[i] == 0){
						
						gos[i].SetActive (true);
						states[i]=1;
 
					}
				}
				gt = "";
			}
			else
			{
				gt += c;
			}

		}
	}
	bool isiton(){
		bool gogo = false;
		for (int i = 0; i < 2; i++) {
			if (states [i] == 0) {
				gogo = false;
			} else {
				gogo = true;
			}
		}
		return gogo;
	}
	void off() {
		for (int i = 0; i < 2; i++) {
			GameObject go = gos [i];
			go.SetActive (false);
			states[i]=0;
		}
	}
}
