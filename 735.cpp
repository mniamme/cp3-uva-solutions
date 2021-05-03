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

int x;
vector<int> v;
set<vector<int> > perm, comb;
void generate (int sum, int level) {
	if (level == 3) {
		int temp = x - accumulate(v.begin(), v.end(), 0);
		int temp2 = temp / 2, temp3 = temp / 3;
		if (temp >= 0) {
			if (temp <= 20 || (temp2 <= 20 && temp2 * 2 == temp) || (temp3 <= 20 && temp3 * 3 == temp) || temp == 50) {
				vector<int> vtemp(v);
				vtemp.push_back(temp);
				perm.insert(vtemp);
				sort(vtemp.begin(), vtemp.end());
				comb.insert(vtemp);
			}
		}
		return;
	}
	for (int i = 0; i <= 20; i++) {
		if (sum - i >= 0) {
			v.push_back(i);
			generate(sum - i, level + 1);
			v.pop_back();
		}
		if (sum - i * 2 >= 0) {
			v.push_back(i * 2);
			generate(sum - i * 2, level + 1);
			v.pop_back();
		}
		if (sum - i * 3 >= 0) {
			v.push_back(i * 3);
			generate(sum - i * 3, level + 1);
			v.pop_back();
		}
		if (sum - 50 >= 0 ) {
			v.push_back(50);
			generate(sum - 50, level + 1);
			v.pop_back();
		}
	}
	
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	while(cin >> x) {
		if (x <= 0) {
			printf("END OF OUTPUT\n");
			return 0;
		}
		v.clear();
		perm.clear();
		comb.clear();
		generate(x, 1);
		if((int)perm.size() == 0) {
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", x);
			printf("**********************************************************************\n");

		}
		else {
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", x, (int)comb.size());
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", x, (int)perm.size());
			printf("**********************************************************************\n");
		}
	}
	return 0;
}