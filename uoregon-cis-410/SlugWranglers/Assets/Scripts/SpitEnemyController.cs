using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class SpitEnemyController : MonoBehaviour {

	private GameObject player;
	private GameObject enemy;
	private SpriteRenderer enemyRenderer;

	public float procRadius = 7.0f;
	private Animator myAnimator;




	void Start () {
		player = GameObject.FindGameObjectWithTag ("Player");
		enemy = this.gameObject;
		enemyRenderer = GetComponent<SpriteRenderer> ();
		myAnimator =  GetComponent<Animator> ();

	}

	void Update() {
	}

	void FixedUpdate () {
		float distanceToPlayer = Vector3.Distance (transform.position, player.transform.position);

		// Chase player if close
		if (distanceToPlayer < procRadius) {
			myAnimator.SetBool ("move", true);
		} else {
			myAnimator.SetBool ("move", false);
		}

		if (distanceToPlayer <= 4.0f) {
			myAnimator.SetBool ("attack", true);
		} else {
			myAnimator.SetBool ("attack", false);
		}


	}
		
		
}
