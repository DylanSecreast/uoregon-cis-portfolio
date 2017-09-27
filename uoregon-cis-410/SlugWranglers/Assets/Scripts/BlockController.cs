using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BlockController : MonoBehaviour {

	public float outDamagePerHit = 5.0f;
	public float damageMultiplier = 1.0f;

	void OnCollisionStay2D(Collision2D other) {
		// IF WITH ENEMY
		if (other.gameObject.CompareTag ("Enemy")) {
			// Get current enemy references
			GameObject currentEnemy = other.gameObject;
			EnemyController enemyController = currentEnemy.GetComponent<EnemyController> ();

			// Do damage to enemy
			enemyController.takeDamage (outDamagePerHit * damageMultiplier);
			Debug.Log ("Block attacking enemy");
		}
	}
}