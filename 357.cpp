#include <bits/stdc++.h>

using namespace std;
vector<int> coinValue = { 1, 5, 10, 25, 50 };

long long table[5][30010];

long long ways(int type, int value) {
	if (type == 5 || value < 0) {
		return 0;
	}
	if (value == 0) {
		return 1;
	}
	if (table[type][value] != -1) {
		return table[type][value];
	}
	return table[type][value] = ways(type + 1, value)
			+ ways(type, value - coinValue[type]);
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	int n;
	memset(table, -1, sizeof table);
	while (cin >> n) {
		long long ans = ways(0, n);
		if (ans == 1) {
			printf("There is only 1 way to produce %d cents change.\n", n);
		} else {
			printf("There are %lld ways to produce %d cents change.\n", ans, n);
		}
	}
	return 0;

}


