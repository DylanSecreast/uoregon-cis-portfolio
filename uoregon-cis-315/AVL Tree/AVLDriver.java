package com.dylansecreast.core;

import java.util.Scanner;

/**
 * AVL Tree
 * @author Dylan Secreast
 * @since 11/18/2015
 * Compiled using JDK 1.8u66
 */

public class AVLDriver {
    public static String command;
    public static int commandArgument;
    public static AVLTree avl = new AVLTree();

    // Get function command and variable from user & verify
    public static void getCommand() {
        System.out.print("Enter command (function integer): ");
        Scanner scan = new Scanner(System.in);
        String input = scan.nextLine();
        if (input.equals("exit")) { printAVL(); }   // exit program, print AVL
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
        switch (command) {
            case "insert":
                avl.insert(commandArgument);
                break;
            case "delete":
                avl.delete(commandArgument);
                break;
            case "search":
                avl.search(commandArgument);
                break;
            default:
                commandError();
        }
        getCommand();
    } // end executeCommand()

    // Call traverse function, exit program
    public static void printAVL() {
        System.out.println("Printing AVL pre-order traversal at runtime exit...");
        avl.traversePreOrder();
        System.exit(0);
    }   // end printAVL()


    public static void main(String[] args) {
        getCommand();
    }   // end main

}   // end class AVLTree //
