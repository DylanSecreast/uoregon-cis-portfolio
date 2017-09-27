package com.dylansecreast.core;

import java.util.Scanner;

/**
 * Binary Search Tree
 *
 * @author Dylan Secreast
 * @since 10/20/15
 */
public class Driver {
    public static String command;
    public static int commandArgument;
    public static BST bst = new BST();

    // Get function command and variable from user & verify
    public static void getCommand() {
        System.out.print("Enter command (function integer): ");
        Scanner scan = new Scanner(System.in);
        String input = scan.nextLine();
        if (input.equals("exit")) { printBST(); }   // exit program, print BST
        String[] parts = input.split("\\s+");   // split string at whitespace(s)
        try { command = parts[0].toLowerCase(); commandArgument = Integer.parseInt(parts[1]); }   // convert commandArgument to int
        catch (Exception e) { commandError(); }   // command argument input was not an int
        if (parts.length != 2) { commandError(); }  // only accept input of a command & argument separated by single whitespace
        executeCommand();
    }   // end getCommand()

    // Display error message & re-prompt if bad input
    public static void commandError() {
        System.out.println("\n<< Invalid input >>");
        System.out.println("Available Functions: insert, delete, search, exit");
        System.out.println("Example: insert 25\n");
        getCommand();   // try again
    } // end commandError()

    // Execute function with given argument
    public static void executeCommand() {
        if (command.equals("insert")) {     // insert, no duplicates
            if (bst.search(bst.root, commandArgument)) { System.out.println("\n<< Can't insert " + commandArgument + ", already in BST >>\n"); }
            else {bst.insert(bst.root, commandArgument); System.out.println("\n<< Successfully inserted " + commandArgument + " >>\n"); }
        } else if (command.equals("delete")) {      // delete if exists
            if (bst.search(bst.root, commandArgument)) { bst.delete(bst.root, commandArgument); System.out.println("\n<< Successfully deleted " + commandArgument + " >>\n"); }
            else { System.out.println("\n<< Can't delete " + commandArgument + ", not in BST >>\n"); }
        } else if (command.equals("search")) {
            System.out.println(bst.search(bst.root, commandArgument) ? "\n<< " + commandArgument + " is in BST >>\n" : "\n<< " + commandArgument + " is not in BST >>\n");
        } else { commandError(); } getCommand();
    } // end executeCommand()

    public static void printBST() {
        System.out.println("\nBST (in-order) at runtime exit:");
        bst.printInOrder(bst.root);
        System.exit(0);
    } // end printBST()


    public static void main(String[] args) { getCommand(); }

} // end class Driver
