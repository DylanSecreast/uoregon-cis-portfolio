using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour {

	public static GameManager Instance;
	public PlayerInfo playerStuff;

	private float timeTrialInSec;
	private List<float> playerScores;	// Leaderboard

	void Start () {
		playerStuff = new PlayerInfo();
		playerScores = new List<float> ();
		Debug.Log ("Started GameManager");
	}

	void Awake ()   
	{
		if (Instance == null)
		{
			DontDestroyOnLoad(gameObject); // Makes the GameManager's gameObject persist through Scene change
			Instance = this;
		}
		else if (Instance != this)
		{
			Destroy (gameObject);
		}
	}
		
	public void GameOver(string sceneName) {
		playerStuff = new PlayerInfo ();
		SceneManager.LoadScene (sceneName);
	}

	public void incrementTimeTrial(float time) {
		timeTrialInSec += time;
	}

	public void resetTimeTrial() {
		timeTrialInSec = 0.0f;
	}

	public float getTimeTrialInSec() {
		return timeTrialInSec;
	}

	public string getTimeStamp(float curTime) {
		int minutes = Mathf.FloorToInt(curTime / 60.0f);
		int seconds = Mathf.FloorToInt(curTime - minutes * 60.0f);
		return string.Format("{00:00}:{1:00}", minutes, seconds);
	}

	public void addPlayerScore(float score) {
		playerScores.Add (score);
		playerScores.Sort ();
	}

	public List<float> getPlayerScores() {
		return playerScores;
	}

	public float getFirstPlace() {
		float score = -1.0f;
		if (playerScores.Count >= 1) {
			score = playerScores [0];
		}
		return score;
	}

	public float getSecondPlace() {
		float score = -1.0f;
		if (playerScores.Count >= 2) {
			score = playerScores [1];
		}
		return score;
	}

	public float getThirdPlace() {
		float score = -1.0f;
		if (playerScores.Count >= 3) {
			score = playerScores [2];
		}
		return score;
	}
}
