package com.dylansecreast.core;

/**
 * The Queue abstract data type class represents a first-in-first-out (FIFO) collection
 * of character data types, implemented using a singly-linked list of nodes.
 * <p>
 * Implemented are the usual enqueue and dequeue atomic operations in O(1) time.
 * In addition, there are methods which determine if the queue is currently empty
 * and returning a string of all current characters in queue.
 *
 * @author Dylan Secreast
 * @version 1.0
 * @since 2015-10-15
 */

class Queue {
	private Node header, footer;
	private final int queueSize;
	private int currentSize;

	/**
	 * Sole constructor: Initializes an empty queue of passed-in size
	 * @param size The size of queue on creation
	 */
	public Queue(int size) {
		header = footer = null;
		queueSize = size;
		currentSize = 0;
	}

	/**
	 * Returns true if queue is currently empty
	 * @return True if empty; false otherwise
	 */
	private boolean isEmpty() { return header == null; }

	/**
	 * Adds character to queue
	 * @param c The specific character being added to queue
	 * @throws RuntimeException If queue has reached full capacity and therefore can't add new character
	 */
	public void enqueue(char c) {
		if (currentSize == queueSize) { throw new RuntimeException("Queue overflow"); }
		Node oldFooter = footer;
		footer = new Node(null, c);
		if (isEmpty()) { header = footer; }
		else { oldFooter.next = footer; }
		currentSize++;
	}

	/**
	 * Removes and returns character from queue
	 * @return The specific character being removed from queue
	 * @throws RuntimeException If queue is empty and therefore can't remove a character
	 */
	public char dequeue() {
		if (isEmpty()) { throw new RuntimeException("Queue underflow"); }
		char returnChar = header.data;
		header = header.next;
		currentSize--;
		if (isEmpty()) { footer = null; }
		return returnChar;
	}

	/**
	 * Returns string of all existing characters currently in queue
	 * @return String of all characters in queue separated by spaces
	 */
	public String toString() {
		StringBuilder s = new StringBuilder();
		while (header != null) {
			s.append(header.data).append(" ");
			header = header.next;
		}
		return s.toString();
	}
}
