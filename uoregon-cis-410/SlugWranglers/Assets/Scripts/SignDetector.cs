using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class SignDetector : MonoBehaviour {

	private bool isTextDisplaying = false;

	public string signText;
	public string helpText;
	public string whatItSays;

	public string guiSignText = "";

	public bool showHelpText = false;
	public Texture2D BoxTexture;
	public Font signFont;


	void Start () {
		// set the text on sign blank
		signText = "";
		helpText = "";
		BoxTexture = Texture2D.blackTexture;
	}
		
	void OnGUI() {
		if (showHelpText) {
			GUI.contentColor = Color.white;
			GUI.skin.textArea.fontSize = 24;
			GUI.skin.textArea.richText = true;
			GUI.skin.textArea.wordWrap = true;
			GUI.skin.font = signFont;
			helpText = GUI.TextArea(new Rect(200, 10, 260, 60), "<b>Push 'L' to interact with signs and other items!</b>", 200);
		}

		if (isTextDisplaying) {
			GUI.contentColor = Color.white;
			GUI.skin.textArea.fontSize = 24;
			GUI.skin.textArea.richText = true;
			GUI.skin.textArea.wordWrap = true;
			GUI.skin.font = signFont;
			signText = GUI.TextArea(new Rect(200, 150, 260, 80), "<b>"+whatItSays+"</b>", 200);
		}
	}

	void OnTriggerStay2D(Collider2D other) {
		if (other.gameObject.CompareTag ("Player")) {
			if (Input.GetKeyDown (KeyCode.L)) {
				if (!isTextDisplaying) {
					DisplayText ();
				} else {
					RemoveText ();
				}
			}
			showHelpText = true;
		}
	}

	void OnTriggerExit2D(Collider2D other) {
		if (other.gameObject.CompareTag ("Player")) {
			isTextDisplaying = false;
			signText = "";
			helpText = "";
			showHelpText = false;
		}
	}

	private void RemoveText() {
		isTextDisplaying = false;
		signText = "";
	}

	private void DisplayText() {
		isTextDisplaying = true;
		signText = whatItSays; //"How to play: Collect items throughout the world, defeat enemies, and find portals to unlock other levels!";
	}

}