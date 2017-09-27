using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraController : MonoBehaviour {
	private Vector3 offset;
	public GameObject player;

	void Start () {
		Vector3 zStuff = new Vector3(0,0,10);
		transform.position = player.transform.position - zStuff;
		offset = transform.position - player.transform.position;

	}
		
	void LateUpdate () {
		transform.position = player.transform.position + offset;
	}
}
