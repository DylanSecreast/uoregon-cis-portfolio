using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class pauseItYo : MonoBehaviour {
	public Transform canvas;
	private PlayerController playerController;

	// Use this for initialization
	void Start () {
		canvas.gameObject.SetActive (false);
		playerController = GetComponent<PlayerController> ();
	}

	// Update is called once per frame
	void Update () {
		if (Input.GetKeyDown (KeyCode.Escape)) {
			if (canvas.gameObject.activeInHierarchy == true) {
				canvas.gameObject.SetActive (false);
				playerController.setIsPaused (false);
				Time.timeScale = 1;
			} else {
				canvas.gameObject.SetActive (true);
				playerController.setIsPaused (true);
				Time.timeScale = 0;
			}

		}

	}

	public void Restart() {
		Time.timeScale = 1;
		GameManager.Instance.playerStuff = new PlayerInfo ();
		GameManager.Instance.resetTimeTrial ();
		SceneManager.LoadScene ("Overworld");
	}
}