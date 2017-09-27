package com.dylansecreast.core;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

public class OccurrenceSet<T> implements Set<T>, Iterable<T> {
	private HashMap<T, Integer> hm = new HashMap<T, Integer>();

	@Override
	public boolean add(T itemToAdd) {
		int newKey;
		if (hm.containsKey(itemToAdd)){		// If key passed in already exists,
			newKey = hm.get(itemToAdd);
			newKey++;			// Increment to next key
		}
		else {					// If key is not already in HashMap, assume HashMap is empty
			newKey = 1;			// Set first key in HashMap
		}
		hm.put(itemToAdd, newKey);		// Add element t to HashMap with newKey
		return true;
	}

	@Override
	public boolean addAll(Collection<? extends T> setToAdd) {
		boolean result = true;
		Iterator<? extends T> setIterator = setToAdd.iterator();	// create new iterator
		while (setIterator.hasNext()) {					// while setToAdd still has values,
			add(setIterator.next());				// send to add() function
		}
		return result;							// returns true if addAll() was successful, false if unsuccessful
	}

	@Override
	public void clear() {
		hm.clear();	// clears all of HashMap
	}

	@Override
	public boolean contains(Object itemToVerify) {
		boolean result = false;
		if (hm.containsKey(itemToVerify)) {	// if Object t is in HashMap
			result = true;			// return true
		}
		else {
			result = false;			// else, return false
		}
		return result;
	}

	@Override
	public boolean containsAll(Collection<?> setToVerify) {
		boolean result = false;
		Iterator<?> setIterator = setToVerify.iterator();		// create new iterator
		while (setIterator.hasNext()) {					// while setToVerify still has values,
			if (setToVerify.contains(setIterator.next())) {		// if element in setToVerify is not in HashMap,
				result = true;					// then HashMap does not contain all of setToVerify
				//break;					// only need to discover one element of setToVerify that's not in HashMap to exit loop
			}
			else {
				result = false;
				break;
			}
		}
		return result;
	}

	@Override
	public boolean isEmpty() {
		boolean result = hm.isEmpty();		// boolean check if HashMap is empty
		return result;				// return check results
	}

	@Override
	public Iterator<T> iterator() {
		Collection c = hm.values();		// turn HashMap into collection
		Iterator<?> itr = c.iterator();		// create iterator of collection
		return null;
	}

	@Override
	public boolean remove(Object itemToRemove) {
		if (contains(itemToRemove)){		// if value exists in HashMap,
			hm.remove(itemToRemove);	// remove it
			return true;
		}
		return false;
	}

	@Override
	public boolean removeAll(Collection<?> setToRemove) {
		boolean result = false;					// will return false if setToRemove is not contained in HashMap
		Iterator<?> setIterator = setToRemove.iterator();	// create new iterator
		if (containsAll(setToRemove)) {				// send setToRemove to containsAll() to return boolean status of set, if true,
			while (setIterator.hasNext()) {			// cycle through all elements in setToRemove
				remove(setIterator.next());		// remove each individual element in setToRemove
			}
			result = true;					// return successful removeAll() boolean status
		}
		return result;
	}

	@Override
	public boolean retainAll(Collection<?> setToRetain) {
		boolean result = false;
		if (containsAll(setToRetain)) {					// if setToRetain exists within HashMap
			clear();						// clear HashMap
			addAll((Collection<? extends T>) setToRetain);		// add setToRetain to HashMap
			result = true;						// return true, method successful
		}
		return result;
	}

	@Override
	public int size() {
		int size = hm.size();	// find size of HashMap
		return size;
	}


	@Override
	public Object[] toArray() {
		ArrayList<Map.Entry<T, Integer>> entries = new ArrayList<>(hm.entrySet());		// copy HashMap to new ArrayList "entries"
		Collections.sort(entries, new Comparator<Map.Entry<T, Integer>>() {			// sort ArrayList
			public int compare(Map.Entry<T, Integer> o1, Map.Entry<T, Integer> o2) {	// compare ArrayList elements
				return o1.getValue().compareTo(o2.getValue());
			}
		});
		Object[] sortedArray = new Object[entries.size()];		// create array "sortedArray" with size of ArrayList
		for (int i = 0; i < entries.size(); i++) {			// cycle through each ArrayList element
			sortedArray[i] = entries.get(i).getKey();		// fill sortedArray with keys from ArrayList
		}
		return sortedArray;
	}

	@Override
	public <T> T[] toArray(T[] a) {
		ArrayList<Map.Entry<T, Integer>> entries = new ArrayList<>();				// copy HashMap to new ArrayList "entries"
		Collections.sort(entries, new Comparator<Map.Entry<T, Integer>>() {			// sort ArrayList
			public int compare(Map.Entry<T, Integer> o1, Map.Entry<T, Integer> o2) {	// compare ArrayList elements
				return o1.getValue().compareTo(o2.getValue());
			}
		});
		T[] sortedArray = (T[]) new Object[entries.size()];	// create array "sortedArray" with size of ArrayList
		for (int i = 0; i < entries.size(); i++) {		// cycle through each ArrayList element
			sortedArray[i] = entries.get(i).getKey();	// fill sortedArray with keys from ArrayList
		}
		return sortedArray;
	}

	public String toString() {
		StringBuilder sb = new StringBuilder();							// create new StringBuilder
		ArrayList<Map.Entry<T, Integer>> entries = new ArrayList<>(hm.entrySet());		// copy HashMap to new ArrayList "entries"
		Collections.sort(entries, new Comparator<Map.Entry<T, Integer>>() {			// sort ArrayList
			public int compare(Map.Entry<T, Integer> o1, Map.Entry<T, Integer> o2) {	// compare ArrayList elements
				return o1.getValue().compareTo(o2.getValue());
			}
		});
		for (int i = 0; i < entries.size(); i++) {		// cycle though each ArrayList element
			sb.append(entries.get(i).getKey() + " ");	// add each ArrayList element to StringBuilder
		}
		String result = sb.toString();				// send StringBuilder to String "result"
		return result;
	}

}	// end class OccurrenceSet
