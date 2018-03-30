import java.io.*;
import java.util.*;

class DisjointSet {
	private int[] parent;
	private int[] rank;
	private int[] no;

	public DisjointSet(int N) {

		parent = new int[N + 1];
		rank = new int[N + 1];
		no = new int[N + 1];
		for (int i = 0; i < N; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < N; i++) {
			rank[i] = 1;
		}
		for (int i = 0; i < N; i++) {
			no[i] = 1;
		}
	}

	public int union(int node1, int node2) {
		int root1, root2;
		root1 = root(node1);
		root2 = root(node2);
		int ans;
		if (root1 != root2) {
			if (rank[root1] > rank[root2]) {
				parent[root2] = root1;
				no[root1] += no[root2];
				ans = no[root1];
			} else if (rank[root1] < rank[root2]) {
				parent[root1] = root2;
				no[root2] += no[root1];
				ans = no[root2];
			} else {
				parent[root2] = root1;
				no[root1] += no[root2];
				ans = no[root1];
				rank[root1]++;
			}
			return ans;
		} else {
			return no[root1];
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
	int first;
	int second;
}

public class Main {

	public static void main(String[] args) throws IOException {

		Scanner in = new Scanner(System.in);
		// PrintWriter out = new PrintWriter("out.txt");
		int T, F;
		T = in.nextInt();
		for (int z = 0; z < T; z++) {
			F = in.nextInt();
			TreeMap<String, Integer> mp = new TreeMap<>();
			String s1, s2;
			ArrayList<Pair> ls = new ArrayList<>();
			int curr = 0;
			for (int i = 0; i < F; i++) {
				s1 = in.next();
				s2 = in.next();
				int n1, n2;
				if (mp.containsKey(s1)) {
					n1 = mp.get(s1);
				} else {
					n1 = curr++;
					mp.put(s1, n1);
				}
				if (mp.containsKey(s2)) {
					n2 = mp.get(s2);
				} else {
					n2 = curr++;
					mp.put(s2, n2);
				}
				Pair p = new Pair();
				p.first = n1;
				p.second = n2;
				ls.add(p);
			}
			DisjointSet ds = new DisjointSet(curr + 1);

			for (Pair e : ls) {
				int ans = ds.union(e.first, e.second);
				System.out.println(ans);
				// out.println(ans);
			}

		}
		// out.close();

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

