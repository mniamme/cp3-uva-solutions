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
int M, C;
int price[25][25];
int memo[210][25];
int shop(int money, int g) {
	
	if (money < 0) {
		return -1;
	}
	if (g == C) {
		return M - money;
	}
	if (memo[money][g] != -1) {
		return memo[money][g];
	}
	int mx = -1;
	for (int model = 1; model <= price[g][0]; model++) {
		mx = max (mx, shop(money - price[g][model], g + 1));
	}
	return memo[money][g] = mx;
}

void solve() {
	memset(memo, -1, sizeof(memo));
	int ans = shop(M, 0);
	(ans == -1) ? cout << "no solution": cout << ans;
}	

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int T;
	cin >> T;
	for (int z = 0; z < T; z++) {
		cin >> M >> C;
		for (int i = 0; i < C; i++) {
			cin >> price[i][0];
			for (int j = 1; j <= price[i][0]; j++) {
				cin >> price[i][j];
			}
		}
		
		solve();
		cout << endl;
	}
		

	return 0;
}
