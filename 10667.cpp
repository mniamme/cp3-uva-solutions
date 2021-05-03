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
int S;
int arr[110][110];

void solve() {
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++) {
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
	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++) {
			for (int k = i; k < S; k++) {
				for (int l = j; l < S; l++) {
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
	int p;
	cin >> p;
	while (p--) {
		memset(arr, 0, sizeof(arr));
		cin >> S;
		int n;
		cin >> n;
		for (int z = 0; z < n; z++) {
			int r1, c1, r2, c2;
			cin >> r1 >> c1 >> r2 >> c2;
			for (int i = r1 - 1; i <= r2 - 1; i++) {
				for (int j = c1 - 1; j <= c2 - 1; j++) {
					arr[i][j] = 1;
				}
			}
		}
	
		solve();
	}
	return 0;
}
