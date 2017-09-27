using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class PlayerController : MonoBehaviour {

	// editor access for movement
	public float horizontalSpeed = 2.0f;
	public float verticalSpeed = 2.0f;
	public float sprintMultiplier = 1.0f;
	private bool isSprinting;
	// editor access for health
	public Slider healthBarSlider;
	public float maxHealth = 100;
	public float currentHealth = 100;
	// editor access for Stamina
	public Slider staminaBarSlider;
	public float maxStamina = 100;
	public float currentStamina = 100;
	public float staminaCost = 0.5f;
	public float staminaActiveRegen = 0.2f;
	public float staminaIdleRegen = 0.5f;
	// editor access for combat
	public float inDamagePerHit = 0.1f;
	public float outDamagePerHit = 25.0f;
	public float damageMultiplier = 1.0f;
	private float lastTimeAttacked = 0.0f;
	private bool canAttack;
	// editor access for dashing
	public float lastTimeDashed = 0.0f;
	public bool canDash;
	// editor access for etc
	public bool isPaused;
	public Text timeTrialText;
	//toggleItem menu images
	public Transform swordImage;
	public Transform swordImage_1;
	public Transform swordImage_2;
	private string playerCurrentWeaponString = "";
	private string lastImageString = "";

	//DamageFlasher
	public int flashCount = 10;
	private SpriteRenderer playerRenderer;

	// audio
	public AudioSource audio;
	public AudioClip boop;
	public AudioClip health;
	public AudioClip swordClang;
	public AudioClip attackSound;
	public AudioClip gurgle;
	public AudioClip[] attackSounds;
	int playSound = 0;
	int playAttack = 0;
	public int soundFreq;
	public int attackSoundFreq;
	bool soundRange = false;

	public PlayerInfo localPlayerStuff;
	private GameObject player;
	private Rigidbody2D rb;
	private Vector2 movement;
	private string scene;
	private bool sameLvl;
	private GameObject portal;
	private List<Dictionary<string, float>> inventory;
	private int playerCurrentWeapon;
	private Animator myAnimator;
	private bool animateAttack;
	private bool fistsToggle;


	void Start () {
		// Object that gets passed to the GameManager between Scenes
		localPlayerStuff = new PlayerInfo ();
		initializePlayerStuff ();
		myAnimator =  GetComponent<Animator> ();
		playerRenderer = GetComponent<SpriteRenderer> ();

		// get the GameManager's copy of the PlayerStuff, if it's got some
		PlayerInfo gameManagerInfo = GameManager.Instance.playerStuff;
		if (gameManagerInfo.portaling) {
			localPlayerStuff = gameManagerInfo;
			moveToPortal (localPlayerStuff.portalUsed);
			localPlayerStuff.portaling = false;
		}

		setupAudio ();

		// if it's the first scene, initialize empty inventory
		if (localPlayerStuff.inventory == null) {
			Debug.Log ("inventory is null");
			localPlayerStuff.inventory = new List<Dictionary<string, float>> ();
			Dictionary<string, float> temp = new Dictionary<string, float> ();
			temp.Add ("None", 1.0f);
			localPlayerStuff.inventory.Add (temp);
			localPlayerStuff.playerCurrentWeapon = 0;
			fistsToggle = false;
		} else {
			if (getKey (localPlayerStuff.inventory [localPlayerStuff.playerCurrentWeapon]) == "None") {
				fistsToggle = false;
			} else {
				fistsToggle = true;
			}
		}

		// set up the weapon UI
		activeWeaponUI (localPlayerStuff.playerCurrentWeaponString);
	}

	private void initializePlayerStuff() {
		localPlayerStuff.horizontalSpeed = horizontalSpeed;
		localPlayerStuff.verticalSpeed = verticalSpeed;
		localPlayerStuff.sprintMultiplier = sprintMultiplier;
		localPlayerStuff.maxHealth = maxHealth;
		localPlayerStuff.currentHealth = currentHealth;
		localPlayerStuff.inDamagePerHit = inDamagePerHit;
		localPlayerStuff.maxStamina = maxStamina;
		localPlayerStuff.currentStamina = currentStamina;
		localPlayerStuff.staminaCost = staminaCost;
		localPlayerStuff.staminaActiveRegen = staminaActiveRegen;
		localPlayerStuff.staminaIdleRegen = staminaIdleRegen;
		localPlayerStuff.portaling = false;
		localPlayerStuff.outDamagePerHit = outDamagePerHit;
		localPlayerStuff.damageMultiplier = damageMultiplier;
		localPlayerStuff.canAttack = true;
		localPlayerStuff.canDash = true;
		localPlayerStuff.inventory = inventory;
		localPlayerStuff.playerCurrentWeapon = playerCurrentWeapon;
		localPlayerStuff.isPaused = false;
		animateAttack = false;
		fistsToggle = false;

		player = gameObject;
		rb = GetComponent<Rigidbody2D> ();
		rb.freezeRotation = true;
	}

	private void setupAudio () {
		audio.GetComponent<AudioSource> ();
		audio.clip = boop;
		audio.clip = health;
		audio.clip = swordClang;
		audio.clip = attackSound;
		audio.clip = gurgle;
	}

	private void moveToPortal (string portalName) {
		GameObject destination = GameObject.Find ("Spawn" + portalName);
		if (destination) {
			transform.position = destination.transform.position;
		}
	}

	public void SavePlayer () {
		Debug.Log ("saving player");
		GameManager.Instance.playerStuff = localPlayerStuff;
		GameManager.Instance.playerStuff.saved = true;
	}

	void Update() {
		timeTrial ();
		isDead ();
		myAnimator.SetBool ("attack", animateAttack);

		if(Input.GetKeyDown (KeyCode.P) && fistsToggle){
			animateAttack = true;
			myAnimator.SetBool ("attack", animateAttack);
			slash ();
		}
		soundRange = false;

		// Handle attack cooldown
		myAnimator.SetFloat ("horizontalSpeed", Input.GetAxis ("Horizontal"));
		myAnimator.SetFloat ("verticalSpeed", Input.GetAxis ("Vertical"));

		if (Time.time - lastTimeAttacked > 0.5f) {
			lastTimeAttacked = Time.time;
			localPlayerStuff.canAttack = true;
		}

		if (Input.GetKeyDown (KeyCode.O)) {

			switchWeapon ();
		}

		// Handle dash cooldown
		if (Time.time - lastTimeDashed > 3.0f) {
			lastTimeDashed = Time.time;
			localPlayerStuff.canDash = true;
		}
		staminaBarSlider.value = localPlayerStuff.currentStamina;
		animateAttack = false;
	}

	void FixedUpdate () {
		if (playSound < soundFreq) {
			playSound += 1;
		}
		if (playAttack < attackSoundFreq) {
			playAttack += 1;
		}

		if (!localPlayerStuff.portaling) {
			localPlayerStuff.isPaused = false;
			float dx = Input.GetAxis ("Horizontal");
			float dy = Input.GetAxis ("Vertical");
			healthBarSlider.value = localPlayerStuff.currentHealth;
			staminaBarSlider.value = localPlayerStuff.currentStamina;

			// SPRINT
			if ((Input.GetKey (KeyCode.LeftShift) || (Input.GetKey(KeyCode.RightShift))) && localPlayerStuff.currentStamina >= 0.1) {
				if (dx != 0 || dy != 0) {
					localPlayerStuff.sprintMultiplier += 1.5f;
					localPlayerStuff.currentStamina -= localPlayerStuff.staminaCost;
					staminaBarSlider.value = localPlayerStuff.currentStamina;
				}
			}

			// DASH
			if (Input.GetKey (KeyCode.Space) && localPlayerStuff.canDash && localPlayerStuff.currentStamina >= 0.1) {
				if (dx != 0 || dy != 0) {
					lastTimeDashed = Time.time;
					localPlayerStuff.sprintMultiplier += 5.0f;
					localPlayerStuff.currentStamina -= 1.8f;
					staminaBarSlider.value = localPlayerStuff.currentStamina;
					StartCoroutine (dashFor (0.25f));
				}
			}

			movement = new Vector2 (dx * localPlayerStuff.horizontalSpeed * localPlayerStuff.sprintMultiplier, dy * localPlayerStuff.verticalSpeed * localPlayerStuff.sprintMultiplier) * Time.deltaTime;
			transform.Translate (movement);
			localPlayerStuff.sprintMultiplier = 1.0f;	// reset

			if (dx == 0 && dy == 0) {	// If not moving
				if (localPlayerStuff.currentStamina < localPlayerStuff.maxStamina) {
					localPlayerStuff.currentStamina += localPlayerStuff.staminaIdleRegen;
				}
			} else {
				if (localPlayerStuff.currentStamina < localPlayerStuff.maxStamina) {
					localPlayerStuff.currentStamina += localPlayerStuff.staminaActiveRegen;
				}
			}

		} else {
			localPlayerStuff.isPaused = true;

			transform.localScale -= new Vector3 (0.07f, 0.07f, 0);
			Vector3 towardsPortal = portal.transform.position - transform.position;

			transform.position += towardsPortal.normalized * Time.deltaTime;

			if ((transform.localScale [0] - 0.1) < 0 && (transform.localScale [1] - 0.1) < 0) {
				if (sameLvl) {
					Debug.Log ("changed portaling");
					moveToPortal (scene);
					transform.localScale = new Vector3 (3.0f, 3.0f, 3.0f);
					localPlayerStuff.portaling = false;
					sameLvl = false;
				} else {
					NextLevel ();
				}
			}
		}
	}

	private void timeTrial() {
		if (!SceneManager.GetActiveScene ().name.Equals ("PoC Scene")) {
			if (!localPlayerStuff.isPaused) {
				GameManager.Instance.incrementTimeTrial (Time.deltaTime);
			}
			float curTimeTrial = GameManager.Instance.getTimeTrialInSec ();
			timeTrialText.text = GameManager.Instance.getTimeStamp (curTimeTrial);
		}
	}

	IEnumerator dashFor(float x) {
		yield return new WaitForSeconds(x);
		localPlayerStuff.canDash = false;
	}

	void OnTriggerEnter2D(Collider2D other) {
		Debug.Log ("touched something");
		if (other.gameObject.CompareTag ("Portal")) {
			localPlayerStuff.portaling = true;
			localPlayerStuff.portalUsed = other.GetComponent<PortalController> ().portalNumber.ToString ();
			scene = other.GetComponent<PortalController> ().sceneName;
			portal = other.gameObject;
			//NextLevel ();
		}

		if (other.gameObject.CompareTag ("SameLevelPortal")) {
			Debug.Log ("SameLevelPortal");
			localPlayerStuff.portaling = true;
			sameLvl = true;
			Debug.Log ("changed portaling");
			scene = other.GetComponent<SameLevelPortal> ().portalNumber.ToString ();
			portal = other.gameObject;
		}
			
		if (other.gameObject.CompareTag ("Slime")) {
			Debug.Log ("Entered slime");
			localPlayerStuff.verticalSpeed = localPlayerStuff.horizontalSpeed = 1.5f;
		}

	}

	void OnTriggerExit2D(Collider2D other) {
		if (other.gameObject.CompareTag ("Slime")) {
			Debug.Log ("Left slime");
			localPlayerStuff.verticalSpeed = verticalSpeed;
			localPlayerStuff.horizontalSpeed = horizontalSpeed;
		}
	}

	void NextLevel() {
		Debug.Log("Going away from scene " + SceneManager.GetActiveScene ().name);
		// if going from tutorial -> overworld, reset PlayerInfo
		if (SceneManager.GetActiveScene ().name == "PoC Scene") {
			GameManager.Instance.playerStuff = new PlayerInfo ();
			GameManager.Instance.playerStuff.saved = true;
		}
		// SavePlayer() for all other scene transition
		else {
			SavePlayer ();
			gameObject.SetActive (false);
		}
		Debug.Log ("CHANGE PLACES!!!");
		SceneManager.LoadScene (scene);
	}
		
	void OnCollisionStay2D(Collision2D other) {
		// ENEMY COMBAT
		if (other.gameObject.CompareTag ("Enemy") && localPlayerStuff.currentHealth > 0) {
			// Get current enemy references
			GameObject currentEnemy = other.gameObject;
			EnemyController enemyController = currentEnemy.GetComponent<EnemyController> ();

			// Take damage from enemy
			localPlayerStuff.currentHealth -= localPlayerStuff.inDamagePerHit;
			if (playSound >= soundFreq) {
				if (!SceneManager.GetActiveScene ().name.Equals ("Jstu2")) {
					audio.PlayOneShot (boop);
				} else {
					bossGurgle ();
				}
				playSound = 0;
				StartCoroutine (ShowDamage());
			}
			isDead ();
			// Do damage to enemy

			if (localPlayerStuff.canAttack && Input.GetKeyDown (KeyCode.P)) {
				float weaponDamage = getValue (localPlayerStuff.inventory [localPlayerStuff.playerCurrentWeapon]);
				Debug.Log ("Weapon: " + getKey(localPlayerStuff.inventory[localPlayerStuff.playerCurrentWeapon]) + " Damage: " + weaponDamage);
				enemyController.takeDamage (outDamagePerHit * damageMultiplier * weaponDamage);
				Debug.Log ("Attacked enemy");
				soundRange = true;
			}

		} else if (other.gameObject.CompareTag ("Block")) {
			localPlayerStuff.currentStamina -= (localPlayerStuff.staminaCost/3);

		}
	}

	void isDead() {
		if (localPlayerStuff.currentHealth <= 0.1) {
			GameManager.Instance.GameOver ("GameOverLost");
			player.SetActive(false);
		}
	}

	public void setIsPaused(bool state) {
		localPlayerStuff.isPaused = state;
	}

	void switchWeapon() {
		// if at the last item on inventory, return to first
		if (localPlayerStuff.playerCurrentWeapon == (localPlayerStuff.inventory.Count - 1)) {
			localPlayerStuff.playerCurrentWeapon = 0;
			foreach (var s in localPlayerStuff.inventory[localPlayerStuff.playerCurrentWeapon]) {
				Debug.Log("length of inv:" + localPlayerStuff.inventory.Count);
				Debug.Log("Current weapon key: " + s);
				if (s.Key == "None") {
					Debug.Log ("s.Key:"+s.Key);
					fistsToggle = false;
				} else {
					Debug.Log ("s.Key:"+s.Key);

					fistsToggle = true;
				}
				localPlayerStuff.playerCurrentWeaponString = s.Key;

			}
			activeWeaponUI (localPlayerStuff.playerCurrentWeaponString);
		} else {
			localPlayerStuff.playerCurrentWeapon++;
			foreach (var s in localPlayerStuff.inventory[localPlayerStuff.playerCurrentWeapon]) {
				Debug.Log("length of inv:" + localPlayerStuff.inventory.Count);
				Debug.Log("Current weapon key: " + s);
				if (s.Key == "None") {
					Debug.Log ("s.Key:"+s.Key);
					fistsToggle = false;
				} else {
					Debug.Log ("s.Key:"+s.Key);
					fistsToggle = true;
				}
				localPlayerStuff.playerCurrentWeaponString = s.Key;

			}
			activeWeaponUI (localPlayerStuff.playerCurrentWeaponString);
		}
	}

	float getValue(Dictionary<string, float> dict) {
		float returner = 1.0f;
		foreach (var s in dict) {
			returner = s.Value;
		}
		return returner;
	}

	string getKey(Dictionary<string, float> dict) {
		string returner = "";
		foreach (var s in dict) {
			returner = s.Key;
		}
		return returner;
	}

	void OnTriggerStay2D(Collider2D other) {
		if (other.gameObject.CompareTag ("Health1")) {
			if (Input.GetKeyDown (KeyCode.L)) {
				localPlayerStuff.currentHealth += (maxHealth - localPlayerStuff.currentHealth)/2;
				audio.PlayOneShot (health);
				Destroy (other.gameObject);
			}
		} else if (other.gameObject.CompareTag ("Pickup")) {
			if (Input.GetKeyDown (KeyCode.L)) {
				WeaponController weaponController = other.gameObject.GetComponent<WeaponController> ();
				Dictionary<string, float> temp = new Dictionary<string, float> ();
				temp.Add (other.gameObject.name, weaponController.damage);
				localPlayerStuff.inventory.Add (temp);
				audio.PlayOneShot (swordClang);
				Destroy (other.gameObject);
				Debug.Log ("picked up an item");
			}
		}

		if (other.gameObject.CompareTag ("Lava")) {
			localPlayerStuff.currentHealth -= localPlayerStuff.inDamagePerHit * 2;
		}


	}

	void activeWeaponUI(string gameObjectString){
		Debug.Log ("gameObjectString:" +gameObjectString);
		Debug.Log ("lastImageString:" +lastImageString);

		if (localPlayerStuff.inventory.Count > 1) {
			Debug.Log ("deactivating");
			deactivateWeaponUI ();
		}
		if (gameObjectString == "SwordPickup") {
			swordImage.gameObject.SetActive (true);
		}
		if (gameObjectString == "SwordPickup_1") {
			swordImage_1.gameObject.SetActive (true);
		}
		if (gameObjectString == "SwordPickup_2") {
			swordImage_2.gameObject.SetActive (true);
		}
		lastImageString = gameObjectString;
	}

	void deactivateWeaponUI(){

		if (lastImageString == "SwordPickup") {
			swordImage.gameObject.SetActive (false);
		}
		if (lastImageString == "SwordPickup_1") {
			swordImage_1.gameObject.SetActive (false);
		}
		if (lastImageString == "SwordPickup_2") {
			swordImage_2.gameObject.SetActive (false);
		}
	}

	IEnumerator ShowDamage() {
		for (int i = 0; i < flashCount; i++) {
			playerRenderer.color = Color.red;
			yield return new WaitForSeconds (0.2f);
			playerRenderer.color = Color.white;
			yield return new WaitForSeconds (0.5f);
		}

	}
	void slash()
	{
		if (playAttack >= attackSoundFreq && soundRange) {
			int random = Random.Range (0, attackSounds.Length);
			audio.clip = attackSounds [random];
			audio.PlayOneShot (attackSounds [random]);
			playAttack = 0;
		}
	}
	void bossGurgle(){
		if (audio.isPlaying) return;
		audio.PlayOneShot (gurgle);
	}

}