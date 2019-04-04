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
	vector<int> parent, rank;
public:
	UnionFind(int N) {
		rank.assign(N, 1);
		parent.assign(N, 0);
		for (int i = 0; i < N; ++i) {
			parent[i] = i;
		}
	}
	int findSet(int v) {
		if (parent[v] == v) {
			return v;
		}
		return findSet(parent[v]);
	}
	bool sameSet(int a, int b) {
		return findSet(a) == findSet(b);
	}
	void unionSet(int a, int b) {
		if (!sameSet(a, b)) {
			int x = findSet(a);
			int y = findSet(b);
			if (rank[x] < rank[y]) {
				swap(x, y);
			}
			parent[y] = x;
			rank[x] += rank[y];
		}
	}
	int maxSize() {
		return *max_element(rank.begin(), rank.end());
	}
};
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	for (int z = 0; z < t; ++z) {
		int n, m;
		cin >> n >> m;
		UnionFind uf(n + 1);
		for (int j = 0; j < m; ++j) {
			int a, b;
			cin >> a >> b;
			uf.unionSet(a, b);
		}
		cout << uf.maxSize() << endl;
	}
	return 0;
}


