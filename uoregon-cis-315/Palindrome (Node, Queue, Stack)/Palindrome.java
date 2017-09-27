package com.dylansecreast.core;

/**
 * The Palindrome class is a driver class to test functionality of Queue
 * and Stack data structures.
 * <p>
 * Prompts user for string to test if palindrome or not by iterating through
 * character-by-character, comparing with queue's FIFO and stack's LIFO.
 * If each character matches in both data structures for whole string, then
 * string is a palindrome. Reports with results.
 *
 * @author Dylan Secreast
 * @version 1.0
 * @since 2015-10-15
 */

import java.util.Scanner;

class Palindrome {
	private static String input, output;
	private static Queue q;
	private static Stack s;

	/**
	 * Prompts user for string to test if palindrome via terminal
	 */
	private static void getInput() {
		System.out.print("Enter string to test it's a palindrome: ");
		Scanner scan = new Scanner(System.in);
		input = scan.nextLine();
		output = input;
		input = input.replaceAll("\\W", "").toLowerCase();	// remove whitespace & punctuation, convert to lowercase
	}

	/**
	 * Creates queue based on input string size; iterates through string
	 * enqueuing character-by-character
	 */
	private static void createFillQueue() {
		q = new Queue(input.length());
		for (int i = 0; i < input.length(); i++) {
			q.enqueue(input.charAt(i));
		}
	}

	/**
	 * Creates stack based on input string size; iterates through string
	 * pushing character-by-character
	 */
	private static void createFillStack() {
		s = new Stack(input.length());
		for (int i = 0; i < input.length(); i++) {
			s.push(input.charAt(i));
		}
	}

	/**
	 * Iterates through each character of input string, comparing characters
	 * in queue and stack - if both dequeue and pop characters match for whole
	 * string, string is a palindrome
	 * @return True if palindrome; false otherwise
	 */
	private static boolean isPalindrome() {
		boolean returnBool = true;
		for (int i = 0; i < input.length(); i++) {
			if (q.dequeue() != s.pop()) { returnBool = false; }
		}
		return returnBool;
	}

	/**
	 * Driver to test if input string is a palindrome - prompts for user
	 * input via terminal and reports with results
	 * @param args
	 */
	public static void main(String[] args) {
		getInput();
		createFillQueue();
		createFillStack();
		if (isPalindrome()) { System.out.print("'" + output + "'" + " is a palindrome!"); }
		else { System.out.print("'" + output + "'" + " is not a palindrome."); }
	}
}
