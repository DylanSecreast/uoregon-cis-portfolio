package com.dylansecreast.core;

/**
 * AVL Tree
 * @author Dylan Secreast
 * @since 11/18/2015
 * Compiled using JDK 1.8u66
 */

public class Node {
    public Node left, right, parent;
    public int data, height, balance;

    // Constructor
    public Node(int d, Node p) {
        data = d;
        parent = p;
        left = right = null;
        height = balance = 0;
    }

}   // end class Node
