import java.io.*;
import java.util.*;

class DisjointSet {
	private int[] parent;
	private int[] rank;
	int religion;

	public DisjointSet(int N) {

		parent = new int[N + 1];
		rank = new int[N + 1];
		religion = N;
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
			religion--;
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

public class Main {

	public static void main(String[] args) throws IOException {
		int n, m;
		int c = 1;
		Scanner in = new Scanner(System.in);
		while (true) {
			n = in.nextInt();
			m = in.nextInt();
			if (n == 0 && m == 0) {
				break;
			}
			DisjointSet ds = new DisjointSet(n);

			for (int i = 0; i < m; i++) {
				int x, y;
				x = in.nextInt();
				y = in.nextInt();
				ds.union(x, y);
			}
			System.out.println("Case " + c++ + ": " + ds.religion);
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

