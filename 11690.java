import java.io.*;
import java.util.*;

class DisjointSet {
	private int N;
	private int[] parent;
	private int[] rank;
	private int[] owe;

	public DisjointSet(int N, int[] owe) {
		this.N = N;
		this.owe = owe;
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
				owe[root1] += owe[root2];
				owe[root2] = 0;
			} else if (rank[root1] < rank[root2]) {
				parent[root1] = root2;
				owe[root2] += owe[root1];
				owe[root1] = 0;
			} else {
				parent[root2] = root1;
				rank[root1]++;
				owe[root1] += owe[root2];
				owe[root2] = 0;
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

	public String getAns() {
		for (int i = 0; i < this.N; i++) {
			if (owe[i] != 0) {
				return "IMPOSSIBLE";
			}
		}
		return "POSSIBLE";
	}
}

public class Main {

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		int t;
		t = in.nextInt();
		for (int z = 0; z < t; z++) {
			int n, m;
			n = in.nextInt();
			m = in.nextInt();
			int[] arr = new int[n];
			for (int i = 0; i < n; i++) {
				arr[i] = in.nextInt();
			}
			DisjointSet ds = new DisjointSet(n, arr);
			for (int i = 0; i < m; i++) {
				int x, y;
				x = in.nextInt();
				y = in.nextInt();
				ds.union(x, y);
			}
			System.out.println(ds.getAns());

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

