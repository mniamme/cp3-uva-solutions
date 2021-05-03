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
int N, M;
int arr[1010][1010];

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i > 0) {
				arr[i][j] += arr[i - 1][j];
			}
			if (j > 0) {
				arr[i][j] += arr[i][j -1];
			}
			if (i > 0 && j > 0) {
				arr[i][j] -= arr[i - 1][j - 1];
			}
		}
	}
	long long  acc = 0;
	for (int i = 0; i < N - M + 1; i++) {
		for (int j = 0; j < N - M + 1; j++) {
			int sr = i, sc = j, er = i + M - 1, ec = j + M - 1;

			int sum = arr[er][ec];
			if (sr > 0) {
				sum -= arr[sr-1][ec];
			}
			if (sc > 0) {
				sum -= arr[er][sc - 1];
			}
			if (sr > 0 && sc > 0) {
				sum += arr[sr - 1][sc - 1];
			}
			cout << sum << endl;
			acc += (long long) sum;
		}
	}
	cout << acc << endl;
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	bool check = false;
	while (cin >> N >> M) {
		if (check) {
			cout << endl;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		solve();
		check = 1;
	}
	return 0;
}
