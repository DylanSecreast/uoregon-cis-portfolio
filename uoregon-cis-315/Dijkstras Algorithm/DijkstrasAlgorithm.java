import java.util.Arrays;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Dylan Secreast
 * 2/29/16
 *
 * Takes standard input:
 * java DijkstrasAlgorithm < inSmall.txt
 */

public class countPaths {
	private static int[] init(int size, int n) {
		int[] dist = new int[size+1];
		for (int i = 0; i < size+1; i++) {
	        dist[i] = n;
	    }

	    return dist;
	}		// end init()

	public static int shortestPath(ArrayList<ArrayList<Integer>> adjList, int size) {
		int[] dist = init(size, Integer.MAX_VALUE);
		dist[1] = 0;

		for (int i = 1; i< size; i++){
			ArrayList<Integer> edges = adjList.get(i);
			for (int each: edges) {
				if (dist[each] > dist[i] + 1) {
					dist[each] = dist[i] + 1;
				}
			}
		}

		return dist[size];
	}		// end shortestPath()

	public static int longestPath(ArrayList<ArrayList<Integer>> adjList, int size){
		int[] dist = init(size, Integer.MIN_VALUE);
		dist[1] = 0;

		for (int i = 1; i< size; i++){
			ArrayList<Integer> edges = adjList.get(i);
			for (int each: edges) {
				if (dist[each] < dist[i] + 1) {
					dist[each] = dist[i] + 1;
				}
			}
		}

		return dist[size];
	}		// end longestPath()

	public static int numPaths(ArrayList<ArrayList<Integer>> adjList, int size) {
		int[] numPaths = init(size, 0);
		numPaths[1] = 1;

		for (int i =1; i <size; i++) {
			ArrayList<Integer> edges = adjList.get(i);
			for (int each: edges) {
				numPaths[each] += numPaths[i];
			}
		}

		return numPaths[size];
	}		// end numPaths()

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int numGraphs = scanner.nextInt();

		for (int i = 0; i < numGraphs; i++) {
			System.out.println("Graph Number: " + (i+1));
			int numVertices = scanner.nextInt();
			int numEdges = scanner.nextInt();

			ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
			for (int j=0; j < numVertices; j++){
				adj.add(new ArrayList<Integer>());
			}
			for (int k = 0; k < numEdges*2; k=k+2) {
				adj.get(scanner.nextInt()).add(scanner.nextInt());
			}

			System.out.println("Shortest Path: " + shortestPath(adj, numVertices));
			System.out.println("Longest Path: " + longestPath(adj, numVertices));
			System.out.println("Number of Paths: " + numPaths(adj, numVertices));
			System.out.println();
		}

	}		// end main()

}		// end class countPaths
