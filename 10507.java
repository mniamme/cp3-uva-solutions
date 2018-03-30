import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {

		Scanner in = new Scanner(new BufferedInputStream(System.in));
		while (in.hasNext()) {
			int n, m;
			n = in.nextInt();
			m = in.nextInt();
			String awakeString = in.next();
			boolean[] awake = new boolean[26];
			boolean[] slept = new boolean[26];
			for (int i = 0; i < 26; i++) {
				awake[i] = false;
				slept[i] = false;
			}
			for (char c : awakeString.toCharArray()) {
				awake[c - 'A'] = true;
			}
			//////////////////
			boolean[][] connected = new boolean[26][26];
			for (int i = 0; i < 26; i++) {
				for (int j = 0; j < 26; j++) {
					connected[i][j] = false;
				}
			}
			////////////////////
			for (int i = 0; i < m; i++) {
				char[] temp;
				temp = in.next().toCharArray();
				int x, y;
				x = (int) temp[0] - 'A';
				y = (int) temp[1] - 'A';
				connected[x][y] = true;
				connected[y][x] = true;
				if (awake[x] == false) {
					slept[x] = true;
				}
				if (awake[y] == false) {
					slept[y] = true;
				}
			}
			// if all areas are awake
			if (n == awakeString.length()) {
				System.out.println("WAKE UP IN, 0, YEARS");
				continue;
			}
			///////////////////
			int newAwake = 0;
			int years = 0;
			for (int z = 0; z < n - awakeString.length(); z++) {
				ArrayList<Integer> ls = new ArrayList<>();
				for (int i = 0; i < 26; i++) {
					if (slept[i] == true) {
						int c = 0;
						for (int j = 0; j < 26; j++) {
							if (awake[j] == true && connected[i][j] == true) {
								c++;
							}
						}
						if (c >= 3) {
							ls.add(i);
						}
					}
				}
				if (ls.size() > 0) {
					newAwake += ls.size();
					years++;
					for (Integer x : ls) {
						slept[x] = false;
						awake[x] = true;
					}
				}
			}
			if (n - awakeString.length() == newAwake) {
				System.out.printf("WAKE UP IN, %d, YEARS\n", years);
			} else {
				System.out.println("THIS BRAIN NEVER WAKES UP");
			}
		}
	}

}

