package com.dylansecreast.core;

import java.util.ArrayList;

public class Main {
	public static void main(String[] args) {
		OccurrenceSet<Integer> intSet = new OccurrenceSet<Integer>();
		System.out.println("Testing add(T)\n-------------------------------");
		intSet.add(1);
		intSet.add(3);
		intSet.add(5);
		intSet.add(5);
		intSet.add(3);
		intSet.add(3);
		intSet.add(3);
		System.out.println("(set of Integers): " + intSet);
		OccurrenceSet<String> stringSet = new OccurrenceSet<String>();
		stringSet.add("hello");
		stringSet.add("hello");
		stringSet.add("world");
		stringSet.add("world");
		stringSet.add("world");
		stringSet.add("here");
		stringSet.add("I");
		stringSet.add("am");
		System.out.println("(set of Strings): " + stringSet + "\n\n");

		OccurrenceSet<Integer> clearSet = new OccurrenceSet<Integer>();
		System.out.println("Testing clear()\n-------------------------------");
		System.out.print("(before clear): ");
		clearSet.add(1);
		clearSet.add(2);
		clearSet.add(3);
		clearSet.add(4);
		clearSet.add(5);
		clearSet.add(6);
		System.out.println(clearSet);
		System.out.print("(after clear): ");
		clearSet.clear();
		System.out.println(clearSet);
		System.out.print("(adding after clear): ");
		clearSet.add(7);
		clearSet.add(8);
		clearSet.add(9);
		clearSet.add(10);
		System.out.println(clearSet + "\n\n");

		OccurrenceSet<String> addAllSet = new OccurrenceSet<String>();
		System.out.println("Testing addAll(Collection)\n-------------------------------");
		ArrayList<String> addAllList = new ArrayList<>();
		addAllList.add("perruquier");
		addAllList.add("pseudology");
		addAllList.add("platypus");
		addAllList.add("pagophagia");
		addAllList.add("puggle");
		addAllSet.addAll(addAllList);
		System.out.println(addAllSet + "\n\n");

		OccurrenceSet<Character> containsSet = new OccurrenceSet<Character>();
		System.out.println("Testing contains(Object)\n-------------------------------");
		containsSet.add('A');
		containsSet.add('B');
		containsSet.add('C');
		containsSet.add('D');
		System.out.println("(set of Characters): " + containsSet);
		System.out.println("(set contains B?): " + containsSet.contains('B'));
		System.out.println("(set contains X?): " + containsSet.contains('X') + "\n\n");

		OccurrenceSet<Integer> containsAllSet = new OccurrenceSet<Integer>();
		System.out.println("Testing containsAll(Collection)\n-------------------------------");
		containsAllSet.add(1);
		containsAllSet.add(2);
		containsAllSet.add(3);
		containsAllSet.add(4);
		containsAllSet.add(5);
		containsAllSet.add(6);
		ArrayList<Integer> containsAllList = new ArrayList<>();
		containsAllList.add(2);
		containsAllList.add(3);
		containsAllList.add(5);
		System.out.println("(set of Integers): " + containsAllSet);
		System.out.println("(set contains 2, 3, and 5?): " + containsAllSet.containsAll(containsAllList) + "\n\n");

		OccurrenceSet<Integer> isEmptySet = new OccurrenceSet<Integer>();
		System.out.println("Testing isEmpty()\n-------------------------------");
		System.out.println("(empty set): " + isEmptySet);
		System.out.println("(is set empty?): " + isEmptySet.isEmpty());
		isEmptySet.add(1);
		isEmptySet.add(2);
		isEmptySet.add(3);
		System.out.println("(added 3 Integers): " + isEmptySet);
		System.out.println("(is new set empty?): " + isEmptySet.isEmpty() + "\n\n");

		OccurrenceSet<Character> removeSet = new OccurrenceSet<Character>();
		System.out.println("Testing remove(Object)\n-------------------------------");
		removeSet.add('A');
		removeSet.add('B');
		removeSet.add('C');
		removeSet.add('D');
		System.out.println("(set of Characters): " + removeSet);
		removeSet.remove('C');
		System.out.println("(removed 'C' from set): " + removeSet + "\n\n");

		OccurrenceSet<Integer> removeAllSet = new OccurrenceSet<Integer>();
		System.out.println("Testing removeAll(Collection)\n-------------------------------");
		removeAllSet.add(1);
		removeAllSet.add(2);
		removeAllSet.add(3);
		removeAllSet.add(4);
		removeAllSet.add(5);
		removeAllSet.add(6);
		System.out.println("(set of Integers): " + removeAllSet);
		ArrayList<Integer> removeAllList = new ArrayList<>();
		removeAllList.add(2);
		removeAllList.add(4);
		removeAllList.add(6);
		removeAllSet.removeAll(removeAllList);
		System.out.println("(removed 2, 4, and 6): " + removeAllSet + "\n\n");

		OccurrenceSet<Integer> retainAllSet = new OccurrenceSet<Integer>();
		System.out.println("Testing retainAll(Collection)\n-------------------------------");
		retainAllSet.add(1);
		retainAllSet.add(2);
		retainAllSet.add(3);
		retainAllSet.add(4);
		retainAllSet.add(5);
		retainAllSet.add(6);
		System.out.println("(set of Integers): " + retainAllSet);
		ArrayList<Integer> retainAllList = new ArrayList<>();
		retainAllList.add(1);
		retainAllList.add(2);
		retainAllList.add(3);
		retainAllSet.retainAll(retainAllList);
		System.out.println("(retained 1, 2, and 3): " + retainAllSet + "\n\n");

		OccurrenceSet<Character> sizeSet = new OccurrenceSet<Character>();
		System.out.println("Testing size()\n-------------------------------");
		sizeSet.add('A');
		sizeSet.add('B');
		sizeSet.add('C');
		sizeSet.add('D');
		sizeSet.add('E');
		sizeSet.add('F');
		System.out.println("(set of Characters): " + sizeSet);
		System.out.println("(size of set): " + sizeSet.size() + " elements\n\n");

		System.out.println("Note: toArray() and toString() are both used thoughout the tests above");

	}	// end main()
}	// end class Main
