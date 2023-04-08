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

int LIS(vector<int> v) {
	int lis[25];
	lis[0] = 1;
	for (int i = 1; i < (int)v.size(); i++) {
		int mx = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (v[j] < v[i]) {
				mx = max(mx, lis[j] + 1);
			}
		}
		lis[i] = mx;
	}
	return *max_element(lis, lis + (int)v.size());
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	vector<int> in;
	int n = 1;
	vector<pair<int, int> > ns;
	int x;
	int idx = 0;
	while (cin >> x) {
		if (x > n) {
			n = x;			
			ns.push_back(make_pair(n, idx));
		}

		in.push_back(x);
		idx++;
	}

	ns.push_back(make_pair(0, in.size()));
	// for (int i = 0; i < (int)ns.size(); i++) {
	// 	cout << ns[i].first << ' ' << ns[i].second << endl;
	// }


	for (int i = 0; i < (int)ns.size() - 1; i++) {
		vector<vector<int> > v;
		int cnt = 0;
		vector<int> temp;
		for (int j = ns[i].second + 1; j < ns[i + 1].second; j++) {
			if (cnt == ns[i].first) {
				cnt = 0;
				v.push_back(temp);
				temp.clear();
			}
			temp.push_back(in[j]);
			cnt++;
		}
		v.push_back(temp);
		
		for (int j = 0; j < (int)v.size(); j++) {
			int sz = (int)v[i].size(); 
			int arr[sz + 5];
			for (int k = 0; k < (int)v[j].size(); k++) {
				arr[v[j][k]] = k + 1;
			}
			v[j] = vector<int> (arr + 1, arr + sz + 1);
		}
		int mp[25];
		for (int j = 0; j < (int)v[0].size(); j++) {
			mp[v[0][j]] = j + 1;
		}
		
		for (int j = 1; j < (int)v.size(); j++) {
			for (int k = 0; k < (int)v[j].size(); k++) {
				v[j][k] = mp[v[j][k]];
			}
			cout << LIS(v[j]) << endl;
		}
	
	}
	return 0;
}
