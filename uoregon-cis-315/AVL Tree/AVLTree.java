package com.dylansecreast.core;

/**
 * AVL Tree
 * @author Dylan Secreast
 * @since 11/18/2015
 * Compiled using JDK 1.8u66
 */

public class AVLTree {
    Node root;

    // Constructor
    public AVLTree() { root = null; }

    // Insert node into AVL Tree
    public boolean insert(int dataToInsert) {
        if (root == null) { root = new Node(dataToInsert, null); }  // First node in tree
        else {
            Node n = root;
            Node parent;
            while (true) {
                if (n.data == dataToInsert) { return false; }

                parent = n;
                boolean leftOrRight = n.data > dataToInsert;     // Insert in left or right subtree?
                n = leftOrRight ? n.left : n.right;

                if (n == null) {
                    if (leftOrRight) { parent.left = new Node(dataToInsert, parent); }      // Insert to left subtree
                    else { parent.right = new Node(dataToInsert, parent); }     // Insert to right subtree
                    rebalance(parent);  // Rebalance if necessary
                    break;  // Done
                }

            }
        }
        System.out.println("<< Successfully inserted " + dataToInsert + " >>");
        return true;
    }   // end insert()

    // Removes node from tree
    public void delete(int dataToDelete) {
        if (!search(dataToDelete)) {    // Must exist to delete
            System.out.println("<< Unable to delete, " + dataToDelete + " not in tree >>");
            return;
        }
        if (root == null) { return; }

        Node n = root;
        Node parent = root;
        Node delNode = null;
        Node child = root;

        while (child != null) {
            parent = n;
            n = child;
            child = dataToDelete >= n.data ? n.right : n.left;  // Determine left or right child
            if (dataToDelete == n.data) { delNode = n; }
        }

        if (delNode != null) {
            delNode.data = n.data;
            child = n.left != null ? n.left : n.right;
            if (root.data == dataToDelete) { root = child; }
            else {
                if (parent.left == n) { parent.left = child; }
                else { parent.right = child; }
            }
            rebalance(parent);  // Rebalance if necessary
        }
        System.out.println("<< Successfully deleted " + dataToDelete + " >>");
        search(dataToDelete);   // Show data was deleted
    }   // end delete()

    // Search for node in tree
    public boolean search(int dataToSearch) {
        if (searchNode(root, dataToSearch)) {
            System.out.println("<< " + dataToSearch + " is in the tree! >>");
            return true;
        } else {
            System.out.println("<< " + dataToSearch + " is NOT in the tree >>");
            return false;
        }
    }   // end search()

    // Assisting function to search()
    public boolean searchNode(Node n, int dataToSearch) {
        if (n != null) {
            if (n.data == dataToSearch) { return true; }
            else if (n.data > dataToSearch) { return searchNode(n.left, dataToSearch); }
            else if (n.data < dataToSearch) { return searchNode(n.right, dataToSearch); }
        }
        return false;
    }   // end searchNode()

    // Rotate node to the left
    public Node leftRotate(Node n) {
        Node temp = n.right;       // Get right child
        temp.parent = n.parent;    // Get parent
        n.right = temp.left;       // Swap subtree's children

        if (n.right != null) { n.right.parent = n; }    // Reassign child's parent

        temp.left = n;     // Rotate left
        n.parent = temp;   // Reassign parent

        if (temp.parent != null) {     // Reassign parent
            if (temp.parent.right == n) { temp.parent.right = temp; }
            else { temp.parent.left = temp; }
        }

        setBalance(n, temp);   // Recalculate balance

        return temp;
    }   // end leftRotate()

    // Rotate node to the right
    public Node rightRotate(Node n) {
        Node temp = n.left;        // Get left child
        temp.parent = n.parent;    // Get parent
        n.left = temp.right;       // Swap subtree's children

        if (n.left != null) { n.left.parent = n; }  // Reassign child's parent

        temp.right = n;    // Rotate right
        n.parent = temp;   // Reassign parent

        if (temp.parent != null) {     // Reassign parent
            if (temp.parent.right == n) { temp.parent.right = temp; }
            else { temp.parent.left = temp; }
        }

        setBalance(n, temp);   // Recalculate balance

        return temp;
    }   // end rightRotate()

    // Rebalance AVL Tree if necessary
    public void rebalance(Node n) {
        setBalance(n);  // Recalculate balance

        if (n.balance == -2) {
            if (height(n.left.left) >= height(n.left.right)) { n = rightRotate(n); }    // If left-imbalanced
            else { n = leftThenRightRotate(n); }
        }
        else if (n.balance == 2) {
            if (height(n.right.right) >= height(n.right.left)) { n = leftRotate(n); }   // If right-imbalanced
            else { n = rightThenLeftRotate(n); }
        }

        if (n.parent != null) { rebalance(n.parent); }
        else { root = n; }
    }   // end rebalance()

    // Calculates tree's balance value
    public void setBalance(Node... nodes) {
        for (Node n : nodes) { n.balance = height(n.right) - height(n.left); }
    }   // end setBalance()

    // Calculates tree's height
    public int height(Node n) {
        if (n == null) { return -1; }
        return 1 + Math.max(height(n.left), height(n.right));
    }   // end height()

    // Assistant function for left-right rotations
    public Node leftThenRightRotate(Node n) {
        n.left = leftRotate(n.left);
        return rightRotate(n);
    }   // end leftThenRightRotate()

    // Assistant function for right-left rotations
    public Node rightThenLeftRotate(Node n) {
        n.right = rightRotate(n.right);
        return leftRotate(n);
    }   // end rightThenLeftRotate()

    // Call pre-order traversal function using root node
    public void traversePreOrder() {
        if (root != null) { traversePreOrder(root); }
        else { System.out.println ("AVL was empty at runtime exit."); }
    }   // end traverse()

    // Print all elements in AVL in pre-order
    public void traversePreOrder(Node n) {
        if (n != null) {
            System.out.print(n.data + " ");
            traversePreOrder(n.left);
            traversePreOrder(n.right);
        }
    }   // end traversePreOrder()

}   // end class AVLTree
