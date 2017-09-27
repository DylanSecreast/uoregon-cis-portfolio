package com.dylansecreast.core;

/**
 * Binary Search Tree
 *
 * @author Dylan Secreast
 * @since 10/20/15
 */
public class BST {
    Node root;

    // Constructor
    public BST() { this.root = null; }

    // Insert node into BST
    public void insert(Node node, int data) {
        if (node == null) { node = new Node(data); root = node; }   // first node to insert
        else if (data < node.data && node.left == null) {   // insert to left subtree
            node.left = new Node(data); node.left.parent = node; }
        else if (data >= node.data && node.right == null) {     // insert to right subtree
            node.right = new Node(data); node.right.parent = node; }
        else {
            if (data < node.data) { insert(node.left, data); }  // climb down left subtree
            else { insert(node.right, data); }  // climb down right subtree
        }
    } // end insert()

    // Delete node from BST
    public Node delete(Node node, int data) {
        Node p, p2, n;
        if (node == null) { return null; }  // tree is empty
        if (node.data == data) {
            Node lt, rt; lt = node.left; rt = node.right;   // left & right subtree
            if (lt == null && rt == null) { return null; }  // empty subtrees
            else if (lt == null) { p = rt; return p; }      // parent in right subtree
            else if (rt == null) { p = lt; return p; }      // parent in left subtree
            else { p2 = rt; p = rt; while (p.left != null) { p = p.left; } p.left = lt; return p2; }
        }
        if (data < node.data) { n = delete(node.left, data); node.left = n; }   // climb down left subtree
        else { n = delete(node.right, data); node.right = n; }  // climb down right subtree
        return node;
    } // end delete()

    // Return true if node is in tree; false otherwise
    public boolean search(Node node, int data) {
        if (node == null) { return false; }     // empty tree
        else if (node.data == data) { return true; }    // search = root
        else {
            if (data < node.data) { return search(node.left, data); }   // climb down left subtree
            else { return search(node.right, data); }   // climb down right subtree
        }
    } // end search()

    // Print all elements in BST in ascending order
    public void printInOrder(Node node) {
        if (node != null) {
            printInOrder(node.left);
            System.out.print(node.data + "  ");
            printInOrder(node.right);
        }
    } // end printInOrder()

} // end class BST
