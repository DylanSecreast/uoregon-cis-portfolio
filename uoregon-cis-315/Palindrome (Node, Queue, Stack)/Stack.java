package com.dylansecreast.core;

/**
 * The Stack abstract data type class represents a last-in-first-out (LIFO) collection
 * of character data types, implemented using a singly-linked list of nodes.
 * <p>
 * Implemented are the usual push and pop atomic operations in O(1) time.
 * In addition, there are methods which determine if the stack is currently empty
 * and returning a string of all current characters in stack.
 *
 * @author Dylan Secreast
 * @version 1.0
 * @since 2015-10-15
 */

class Stack {
    private Node top;
    private final int stackSize;
    private int currentSize;

    /**
     * Sole constructor: Initializes an empty stack
     * @param size the size of stack on creation
     */
	public Stack(int size) {
        top = null;
        stackSize = size;
        currentSize = 0;
    }

    /**
     * Returns true if stack is currently empty
     * @return True if empty; false otherwise
     */
    private boolean isEmpty() { return top == null; }

    /**
     * Adds character to stack
     * @param c The specific character being added to stack
     * @throws RuntimeException If stack has reached full capacity and therefore can't add new character
     */
    public void push(char c) {
        if (currentSize == stackSize) { throw new RuntimeException("Stack overflow"); }
        top = new Node(top, c);
        currentSize++;
    }

    /**
     *Removes and returns character from stack
     * @return The specific character being removed from stack
     * @throws RuntimeException If stack is empty and therefore can't remove a character
     */
    public char pop() {
        if (isEmpty()) { throw new RuntimeException("Stack underflow"); }
        char oldTop = top.data;
        top = top.next;
        currentSize--;
        if (isEmpty()) { top = null; }
        return oldTop;
    }

    /**
     * Returns string of all existing characters currently in stack
     * @return String of all characters in stack separated by spaces
     */
    public String toString() {
        StringBuilder s = new StringBuilder();
        while (top != null) {
            s.append(top.data).append(" ");
            top = top.next;
        }
        return s.toString();
    }
}
