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
int M, N;
int arr[110][110];

void solve() {
	for (int i = 0; i < M; i++) {
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
	int ans = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = i; k < M; k++) {
				for (int l = j; l < N; l++) {
					int sum = arr[k][l];
					if (i > 0) {
						sum -= arr[i-1][l];
					}
					if (j > 0) {
						sum -= arr[k][j - 1];
					}
					if (i > 0 && j > 0) {
						sum += arr[i - 1][j - 1];
					}
					if (!sum) {
						ans = max (ans, (k - i + 1) * (l - j + 1));
					}
				}
			}
		}
	}
	cout << ans << endl;
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (cin >> M >> N, M && N) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		solve();
	}
	return 0;
}
