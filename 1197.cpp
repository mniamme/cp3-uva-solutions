/*
 *			BATPROBATPROBATPROBATPROBATPROBATPROBATPROBATPROBATPROBATPROBATPR
 * 			BATPROBATPROBATPROBATPROBATPROBATPROBATPROBATPROBATPROBATPROBATPR
 * 			BAT.             `PROBATPROBA|\___/|TPROBATPROB'             .ATP
 * 			BATPR.            `OBATPROBAT|     |PROBATPROBA'           .TPROB
 * 			BATPRO.            `BATPROBA/       \TPROBATP'            .ROBATP
 * 			BATPROB.                                                 .ATPROBA
 * 			BATPROB'                                                 `ATPROBA
 * 			BATPRO'                                                   `BATPRO
 * 			BATPROBATPROBATP`---._                     _.---'ROBATPROBATPROBA
 * 			BATPROBATPROBATPROBATPR--.             .--OBATPROBATPROBATPROBATP
 * 			BATPROBATPROBATPROBATPROBAT-.       .-PROBATPROBATPROBATPROBATPRO
 * 			BATPROBATPROBATPROBATPROBATPRO.   .BATPROBATPROBATPROBATPROBATPRO
 * 			BATPROBATPROBATPROBATPROBATPROB\ /ATPROBATPROBATPROBATPROBATPROBA
 * 			BATPROBATPROBATPROBATPROBATPROBAVTPROBATPROBATPROBATPROBATPROBATP
 *
 */

#include <bits/stdc++.h>

using namespace std;
class UnionFind {
private:
	vector<int> parent;
	vector<int> rank;
public:
	UnionFind(int N) {
		parent.assign(N, 0);
		rank.assign(N, 1);
		for (int i = 0; i < N; ++i) {
			parent[i] = i;
		}
	}

	int findSet(int v) {
		if (parent[v] == v) {
			return v;
		}
		return parent[v] = findSet(parent[v]);
	}

	void UnionSet(int a, int b) {
		a = findSet(a);
		b = findSet(b);
		if (a != b) {

			if (rank[a] < rank[b]) {
				swap(a, b);
			}
			parent[b] = a;
			rank[a] += rank[b];
		}
	}
	int getSize(int v) {
		return rank[parent[v]];
	}
};
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	while (cin >> n >> m, n || m) {
		UnionFind uf(n + 1);
		for (int i = 0; i < m; ++i) {
			int k, v;
			cin >> k >> v;
			for (int j = 0; j < k - 1; ++j) {
				int x;
				cin >> x;
				uf.UnionSet(v, x);
			}
		}
		cout << uf.getSize(0) << endl;
	}
	return 0;
}


