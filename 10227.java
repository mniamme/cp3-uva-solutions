import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		String s;
		s = in.nextLine();
		int n = Integer.parseInt(s);
		s = in.nextLine();
		for (int z = 0; z < n; z++) {
			Integer p, t;
			String[] temp = in.nextLine().split(" ");
			p = Integer.parseInt(temp[0]);
			t = Integer.parseInt(temp[1]);
			ArrayList<ArrayList<Integer>> ls = new ArrayList<>();
			for (int i = 0; i < p + 1; i++) {
				ls.add(new ArrayList<>());
			}
			while (in.hasNext()) {
				s = in.nextLine();
				if (s.length() == 0) {
					break;
				}
				String[] temp2 = s.split(" ");
				int x, y;
				x = Integer.parseInt(temp2[0]);
				y = Integer.parseInt(temp2[1]);
				ls.get(x).add(y);
			}
			int ans = 0;
			boolean[] visited = new boolean[p + 1];
			for (int i = 0; i <= p; i++) {
				visited[i] = false;
			}
			for (int i = 1; i <= p; i++) {
				if (!visited[i]) {
					ArrayList<Integer> tempList1 = new ArrayList<>(ls.get(i));
					Collections.sort(tempList1);
					ans++;
					visited[i] = true;
					for (int j = i + 1; j <= p; j++) {
						ArrayList<Integer> tempList2 = new ArrayList<>(ls.get(j));
						Collections.sort(tempList2);
						if (compare(tempList1, tempList2) == true) {
							visited[j] = true;
						}
					}
				}
			}
			System.out.println(ans);
			if (z < n - 1) {
				System.out.println();
			}
		}
	}

	static boolean compare(ArrayList<Integer> ls1, ArrayList<Integer> ls2) {
		TreeSet<Integer> t1, t2;
		t1 = new TreeSet<>(ls1);
		t2 = new TreeSet<>(ls2);
		ls1 = new ArrayList<>(t1);
		ls2 = new ArrayList<>(t2);
		if (ls1.size() != ls2.size()) {
			return false;
		}
		for (int i = 0; i < ls1.size(); i++) {
			if (ls1.get(i) != ls2.get(i)) {
				return false;
			}
		}
		return true;
	}
}
