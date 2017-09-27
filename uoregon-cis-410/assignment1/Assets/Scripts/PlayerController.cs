using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayerController : MonoBehaviour {
	
	private Rigidbody rb;
	private int count;

	public float speed;
	public Text countText;
	public Text winText;

	void Start () {
		rb = GetComponent<Rigidbody> ();
		count = 0;
		SetCountText ();
		winText.text = "";
	}

	void FixedUpdate () {
		float moveHorizontal = Input.GetAxis ("Horizontal");
		float moveVertical = Input.GetAxis ("Vertical");
		float moveJump = 0.0f;

		// Only jump if touching ground
		if (Input.GetKeyDown ("space") && rb.transform.position.y <= 0.5f) {
			moveJump = 20.0f;
		}

		Vector3 movement = new Vector3 (moveHorizontal, moveJump, moveVertical);
		rb.AddForce (movement * speed);
	}

	void OnTriggerEnter(Collider other) {
		if (other.gameObject.CompareTag ("Pick Up")) {
			other.gameObject.SetActive (false);
			count = count + 1;
			SetCountText ();
		}
	}

	void SetCountText () {
		countText.text = "Count: " + count.ToString ();
		if (count >= 8) {
			winText.text = "You Win!";
		}
	}
}
