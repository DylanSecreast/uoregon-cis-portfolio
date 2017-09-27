using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class lilEnemyController : MonoBehaviour {

	private GameObject player;
	private GameObject enemy;
	private SpriteRenderer enemyRenderer;
	public Slider healthBarSlider;

	public float maxHealth = 100.0f;
	public float procRadius = 7.0f;
	public float speed = 1.25f;
	public float health = 100;
	public int flashCount = 2;


	void Start () {
		player = GameObject.FindGameObjectWithTag ("Player");
		enemy = this.gameObject;
		enemyRenderer = GetComponent<SpriteRenderer> ();
		healthBarSlider.value = maxHealth;
	}

	void Update() {
		isDead ();
	}

	void FixedUpdate () {
		float distanceToPlayer = Vector3.Distance (transform.position, player.transform.position);

		// Chase player if close
		if (distanceToPlayer < procRadius) {
			transform.position = Vector2.MoveTowards(transform.position, player.transform.position, speed * Time.deltaTime);
		}
	}

	public void takeDamage (float hit) {
		isDead ();
		health -= hit;
		healthBarSlider.value -= hit;
		StartCoroutine (ShowDamage ());
	}

	public void isDead() {
		if (health <= 0.1) {
			if (transform.name == "slugBoss") {
				GameManager.Instance.GameOver ("GameOverWon");
			}
			enemy.SetActive (false);
		}
	}

	IEnumerator ShowDamage() {
		for (int i = 0; i < flashCount; i++) {
			enemyRenderer.color = Color.blue;
			yield return new WaitForSeconds (0.2f);
			enemyRenderer.color = Color.white;
			yield return new WaitForSeconds (0.5f);

		}
	}
}
