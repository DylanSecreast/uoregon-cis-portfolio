using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerInfo {

	// Health
	public float maxHealth;
	public float currentHealth;
	// Attack
	public float damagePerHit;
	public float damageMultiplier;
	public float inDamagePerHit;
	public float outDamagePerHit;
	public bool canAttack;
	// Movement
	public float horizontalSpeed;
	public float verticalSpeed;
	public float sprintMultiplier;
	public bool canDash;
	// Stamina
	public float maxStamina;
	public float currentStamina;
	public float staminaCost;
	public float staminaActiveRegen;
	public float staminaIdleRegen;
	// Etc
	public bool isPaused;

	// Marking if stuff has been saved yet - starting as false
	public bool saved = false;

	public bool portaling;
	public string portalUsed;

	// save the inventory across all levels
	public List<Dictionary<string, float>> inventory;
	public int playerCurrentWeapon;
	public string playerCurrentWeaponString = "";

}
