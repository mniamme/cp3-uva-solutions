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
int cA, cB, N;

void move_1 (int A, int B) {
	if (B == N) {
		cout << "success" << endl;
		return;
	}
	if (A == 0) {
		cout << "fill A" << endl;
		move_1(cA, B);
	}
	else if (B == cB) {
		cout << "empty B" << endl;
		move_1(A, 0);
	}
	else {
		cout << "pour A B" << endl;
		move_1(A - min(B + A, cB) + B, min(B + A, cB));
	}
	return;
}

void move_2 (int A, int B) {
	if (B == N) {
		cout << "success" << endl;
		return;
	}
	if (B == 0) {
		cout << "fill B" << endl;
		move_2(A, cB);
	}
	else if (A == cA) {
		cout << "empty A" << endl;
		move_2(0, B);
	}
	else {
		cout << "pour B A" << endl;
		move_2(min(A + B, cA), B - min(A + B, cA) + A);
	}
	return;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	while (cin >> cA >> cB >> N){
		if (N <= cA){
			move_1(0, 0);
		} 
		else {
			move_2(0, 0);
		}
	}
	return 0;
}
