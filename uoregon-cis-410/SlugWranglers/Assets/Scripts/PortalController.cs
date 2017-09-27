using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PortalController : MonoBehaviour {


	public int portalNumber;
	public string sceneName;

	public void ClosePortal() {
		transform.localScale -= new Vector3 (0.07f, 0.07f, 0);
		if ((transform.localScale[0] - 0.1) < 0 && (transform.localScale[1] - 0.1) < 0) {
			gameObject.SetActive (false);
		}
	}
}
