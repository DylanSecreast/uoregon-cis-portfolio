package com.dylansecreast.core;

/**
 * Binary Search Tree
 *
 * @author Dylan Secreast
 * @since 10/20/15
 */
public class Node {
    Node parent, left, right;
    public int data;

    // Constructor
    public Node(int data) {
        this.data = data;
        this.parent = null;
        this.left = null;
        this.right = null;
    }

} // end class Node
