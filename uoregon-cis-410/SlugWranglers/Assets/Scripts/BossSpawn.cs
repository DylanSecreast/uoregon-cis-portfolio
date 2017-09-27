using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class BossSpawn : MonoBehaviour {

	public Slider bossHealthBarSlider;
	public bool canSpawn;

	// Use this for initialization
	void Start () {
		spawnEnemies (false);
		canSpawn = true;
	}
	
	// Update is called once per frame
	void Update () {
		if (canSpawn && bossHealthBarSlider.value < 500) {
			spawnEnemies (true);
			canSpawn = false;
		}
	}

	public void spawnEnemies(bool state) {	// true = spawn, false = hide
		foreach (Transform child in this.transform) {
			child.gameObject.SetActive (state);
		}
	}

}
