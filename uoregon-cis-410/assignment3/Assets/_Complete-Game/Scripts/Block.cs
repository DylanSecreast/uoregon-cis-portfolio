using UnityEngine;
using System.Collections;

namespace Completed
{
	public class Block : MovingObject
	{
		public AudioClip clangSound1;				//1 of 2 audio clips that play when the wall is attacked by the player.
		public AudioClip clangSound2;				//1 of 2 audio clips that play when the wall is attacked by the player.

		public Sprite fallingSprite;					//Alternate sprite to display after Wall has been attacked by player.
		public Sprite fallSprite;					//Alternate sprite to display after Wall has been attacked by player.

		private bool skipMove;							//Boolean to determine whether or not enemy should skip a turn or move this turn.
		private float changeSprite = 0;
		private float hotBlock = 0;
		private Transform target;							//Transform to attempt to move toward each turn.

		private bool displace = false;

		//private SpriteRenderer spriteRenderer;		//Store a component reference to the attached SpriteRenderer.
		//Start overrides the virtual Start function of the base class.
		private SpriteRenderer spriteRenderer;		//Store a component reference to the attached SpriteRenderer.


		protected override void Start ()
		{
			//Register this enemy with our instance of GameManager by adding it to a list of Enemy objects. 
			//This allows the GameManager to issue movement commands.
			GameManager.instance.AddBlockToList (this);
			spriteRenderer = GetComponent<SpriteRenderer> ();


			//Get and store a reference to the attached Animator component.
			//animator = GetComponent<Animator> ();


			//Find the Player GameObject using it's tag and store a reference to its transform component.
			target = GameObject.FindGameObjectWithTag ("Player").transform;

			//Call the start function of our base class MovingObject.
			base.Start ();
		}
			

		//Override the AttemptMove function of MovingObject to include functionality needed for Enemy to skip turns.
		//See comments in MovingObject for more on how base AttemptMove function works.
		protected override void AttemptMove <T> (int xDir, int yDir)
		{
			//Check if skipMove is true, if so set it to false and skip this turn.
			if(skipMove)
			{
				skipMove = false;
				return;

			}

			//Call the AttemptMove function from MovingObject.
			base.AttemptMove <T> (xDir, yDir);

			//Now that Enemy has moved, set skipMove to true to skip next move.
			skipMove = true;
		}
		void FixedUpdate(){
			if (changeSprite  == 1f) {
				spriteRenderer.sprite = fallSprite;

			}
			if (changeSprite  > 0f) {
				changeSprite--;
			}

			if (hotBlock  == 1f) {
				displace = false;
			}
			if (hotBlock  > 0f) {
				hotBlock--;
			}
		}

		//MoveEnemy is called by the GameManger each turn to tell each Enemy to try to move towards the player.
		public void MoveBlock ()
		{
			//Declare variables for X and Y axis move directions, these range from -1 to 1.
			//These values allow us to choose between the cardinal directions: up, down, left and right.
			int xDir = 0;
			int yDir = 0;

			//If the difference in positions is approximately zero (Epsilon) do the following:
			if(Mathf.Abs (target.position.x - transform.position.x) < float.Epsilon)

				//If the y coordinate of the target's (player) position is greater than the y coordinate of this enemy's position set y direction 1 (to move up). If not, set it to -1 (to move down).
				yDir = target.position.y > transform.position.y ? -1 : 1;

			//If the difference in positions is not approximately zero (Epsilon) do the following:
			else
				//Check if target x position is greater than enemy's x position, if so set x direction to 1 (move right), if not set to -1 (move left).
				xDir = target.position.x > transform.position.x ? -1 : 1;

			//Call the AttemptMove function and pass in the generic parameter Player, because Enemy is moving and expecting to potentially encounter a Player
			AttemptMove <Block> (xDir, yDir);
		}


		void Awake ()
		{
			//Get a component reference to the SpriteRenderer.
			//spriteRenderer = GetComponent<SpriteRenderer> ();
		}


		//OnTriggerEnter2D is sent when another object enters a trigger collider attached to this object (2D physics only).
		private void OnTriggerEnter2D (Collider2D other)
		{
			//Check if the tag of the trigger collided with is Exit.
			if (other.tag == "Enemy") {
				if (displace) {
					other.gameObject.SetActive (false);
					displace = false;
				}

			} else if (other.tag == "Player") {
				hotBlock = 500;
				displace = true;
				this.MoveBlock ();
				SoundManager.instance.RandomizeSfx (clangSound1, clangSound2);

			} else if (other.tag == "Wall") {
				other.gameObject.SetActive (false);
			} else if (other.tag == "OuterWall") {
				//Set spriteRenderer to the damaged wall sprite.
				spriteRenderer.sprite = fallingSprite;
				changeSprite = 25;
			}

		}

		protected override void OnCantMove <T> (T component)
		{
		}

	}
}
