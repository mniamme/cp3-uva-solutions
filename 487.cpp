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
int N;
char arr[25][25];
set<string> ans;
void word (vector<char> curr, int x, int y) {
	if (x < 0 || y < 0 || x == N || y == N) {
		return;
	}
	if ((int)curr.size() > 0 && arr[x][y] <= curr.back()) {
		return;
	}
	curr.push_back(arr[x][y]);
	if ((int)curr.size() >= 3) {
		string temp(curr.begin(), curr.end());
		ans.insert(temp);
	}
	word (curr, x + 1, y);
	word (curr, x - 1, y);
	word (curr, x, y + 1);
	word (curr, x, y - 1);
	word (curr, x - 1, y - 1);
	word (curr, x - 1, y + 1);
	word (curr, x + 1, y - 1);
	word (curr, x + 1, y + 1);
	curr.pop_back();
}

bool comp (const string &left, const string &right) {
	if (left.size() < right.size()) {
		return true;
	}
	else if (left.size() == right.size()) {
		for (int i = 0; i <(int)left.size(); i++) {
			if (left[i] < right[i]) {
				return true;
			}
			else if (left[i] > right[i]) {
				return false;
			}
		}
	}
	return false;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int T;
	cin >> T;
	for (int z = 0; z < T; z++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				word(vector<char> (), i, j);
			}
		}
		
		vector<string> vtemp(ans.begin(), ans.end());
		sort(vtemp.begin(), vtemp.end(), comp);
		for (int k = 0; k < (int)vtemp.size(); k++) {
			cout << vtemp[k] << endl;
		}
		ans.clear();
		if (z + 1 != T) {
			cout << endl;
		}
	}	

	return 0;
}
