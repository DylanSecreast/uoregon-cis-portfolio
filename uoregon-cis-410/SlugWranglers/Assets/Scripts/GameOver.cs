using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class GameOver : MonoBehaviour {
	private float finalTimeTrialInSec;
	public Text finalTimeTrialText;

	public Text firstPlaceText;
	public Text secondPlaceText;
	public Text thirdPlaceText;

	// Use this for initialization
	void Start () {
		finalTimeTrialInSec = GameManager.Instance.getTimeTrialInSec (); 
		finalTimeTrialText.text = GameManager.Instance.getTimeStamp (finalTimeTrialInSec); 
		updateLeaderboard ();
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKeyDown (KeyCode.R)) {
			GameManager.Instance.resetTimeTrial ();
			SceneManager.LoadScene ("Overworld");
		}
	}

	private void updateLeaderboard() {
		// Returns score, if exists > 0
		float first = GameManager.Instance.getFirstPlace ();
		float second = GameManager.Instance.getSecondPlace ();
		float third = GameManager.Instance.getThirdPlace ();

		if (first > 0) {
			firstPlaceText.text = GameManager.Instance.getTimeStamp (first);
		} else {
			firstPlaceText.text = "--:--";
		}

		if (second > 0) {
			secondPlaceText.text = GameManager.Instance.getTimeStamp(second);
		} else {
			secondPlaceText.text = "--:--";
		}

		if (third > 0) {
			thirdPlaceText.text = GameManager.Instance.getTimeStamp(third);
		} else {
			thirdPlaceText.text = "--:--";
		}

	}

}
