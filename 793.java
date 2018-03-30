import java.io.*;
import java.util.*;

class DisjointSet {
	private int[] parent;
	private int[] rank;

	public DisjointSet(int N) {

		parent = new int[N + 1];
		rank = new int[N + 1];
		for (int i = 0; i < N; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < N; i++) {
			rank[i] = 1;
		}
	}

	public void union(int node1, int node2) {
		int root1, root2;
		root1 = root(node1);
		root2 = root(node2);
		if (root1 != root2) {
			if (rank[root1] > rank[root2]) {
				parent[root2] = root1;
			} else if (rank[root1] < rank[root2]) {
				parent[root1] = root2;
			} else {
				parent[root2] = root1;
				rank[root1]++;
			}
		}
	}

	public int root(int node) {
		if (node == parent[node]) {
			return node;
		}
		return parent[node] = root(parent[node]);
	}

	public boolean isConnected(int node1, int node2) {
		return root(node1) == root(node2);
	}

}

class Pair {
	int first, second;

}

public class Main {

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		int t;
		t = in.nextInt();
		for (int z = 0; z < t; z++) {
			int n;
			n = in.nextInt();
			DisjointSet ds = new DisjointSet(n);
			int correct = 0, wrong = 0;
			String s = "";
			int c = 0, q = 0;
			while (true) {
				s = in.nextLine();
				if (s == null || s.length() == 0) {
					break;
				}
				String[] arr = s.split(" ");
				int x, y;
				x = Integer.parseInt(arr[1]);
				y = Integer.parseInt(arr[2]);
				if (arr[0].compareTo("c") == 0) {
					ds.union(x, y);
				} else {
					if (ds.isConnected(x, y)) {
						correct++;
					} else {
						wrong++;
					}
				}
			}
			System.out.println(correct + "," + wrong);
			if (z < t - 1) {
				System.out.println();
			}
		}
	}

	static class Scanner {

		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s) {
			br = new BufferedReader(new InputStreamReader(s));
		}

		public Scanner(String s) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(s));
		}

		public String next() throws IOException {
			while (st == null || !st.hasMoreTokens()) {
				st = new StringTokenizer(br.readLine());
			}
			return st.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public String nextLine() throws IOException {
			return br.readLine();
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

		public boolean ready() throws IOException {
			return br.ready();
		}
	}
}

