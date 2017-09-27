package com.dylansecreast.core;

/**
 * A simple node class for creating singly-linked lists of character
 * data types.
 *
 * @author Dylan Secreast
 * @version 1.0
 * @since 2015-10-15
 */

public class Node {
	public Node next;
	public final char data;

	/**
	 * Sole constructor: Initializes a new node
	 * @param n Node to be set as next
	 * @param c Character to be set as data
	 */
	public Node(Node n, char c) {
		data = c;
		next = n;
	}
}
