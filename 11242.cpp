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
bool comp (pair<int, int> &left, pair<int, int> &right) {
	if (left.first * right.second <= right.first * left.second) {
		return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	
	int arr_r[12], arr_f[12];
	int f;
	while (cin >> f, f != 0) {
		int r;
		cin >> r;
		for (int i = 0; i < f; i++) {
			cin >> arr_f[i];
		}
		for (int i = 0; i < r; i++) {
			cin >> arr_r[i];
		}
		vector <pair<int, int> > d;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < f; j++) {
				d.push_back(make_pair(arr_r[i], arr_f[j]));
			}
		}
	
		sort(d.begin(), d.end(), comp);

		pair<int, int> mx = {d[1].first * d[0].second, d[1].second * d[0].first};
		for (int i = 2; i < (int)d.size(); i++) {
			pair<int, int> temp = {d[i].first * d[i-1].second, d[i].second * d[i-1].first};
			if (comp(mx, temp)) {
				mx = temp;
			}
		}
		float result = (float)mx.first / mx.second;
		result = int(result * 100 + 0.5);
		printf("%.2f\n", result / 100);
		
	}

	return 0;
}
