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

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

#define SZ(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define ALLR(v) v.rbegin(),v.rend()
#define FN(s,c) (int)s.find(c)
#define FOR(i,e) for (int i = 0; i < e; i++)
#define MFOR(i,s,e) for (int i = s; i <= e; i++)
#define ROF(i,s) for (int i = s-1; i >= 0; i--)
#define MROF(i,s,e) for (int i = s; i >= e; i--)
#define IT(it,v) for(it=v.begin();it!=v.end();it++)
#define TI(it,v) for(it=v.rbegin();it!=v.rend();it++)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FILL(a,v) memset(a,v,sizeof(a))

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> II;
/*************************************************/
int memo[70][305][305];
VI vmemo[70][305][305];
int rods[70][25];
const int MAX = 300010;
int n;
pair<VI, int> find(int row, int t1, int t2) {
	if (memo[row][t1][t2] != -1) {
		return MP(vmemo[row][t1][t2], memo[row][t1][t2]);
	}
	if (row == 2 * n) {
		return MP(VI(), 0);
	}

	int mn = MAX;
	VI v;
	for (int i = 0; i <= rods[row][0]; i++) {
		if (t1 - i >= 0 && t2 - (rods[row][0] - i) >= 0) {
			pair<VI, int> temp = find(row + 2, t1 - i, t2 - (rods[row][0] - i));
			if (temp.S + rods[row][i + 1] + rods[row + 1][rods[row][0] - i + 1]
					< mn) {
				mn = temp.S + rods[row][i + 1]
						+ rods[row + 1][rods[row][0] - i + 1];
				v.clear();
				v.PB(i);
				FOR(j, SZ(temp.F))
				{
					v.PB(temp.F[j]);
				}
			}
		}
	}
	memo[row][t1][t2] = mn;
	vmemo[row][t1][t2] = v;
	return MP(v, mn);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	int t1, t2;
	while (cin >> t1 >> t2, t1 || t2) {
		FILL(memo, -1);
		cin >> n;
		for (int i = 0; i < 2 * n; i += 2) {
			cin >> rods[i][0];
			rods[i + 1][0] = rods[i][0];
			rods[i][1] = 0;
			rods[i + 1][1] = 0;
			for (int j = 1; j <= rods[i][0]; j++) {
				cin >> rods[i][j + 1];
			}
			for (int j = 1; j <= rods[i][0]; j++) {
				cin >> rods[i + 1][j + 1];
			}
		}
		pair<VI, int> temp = find(0, t1, t2);
		cout << temp.S << endl;
		FOR(i, SZ(temp.F))
		{
			cout << temp.F[i];
			if (i < SZ(temp.F) - 1) {
				cout << ' ';
			}
		}
		cout << endl << endl;
	}
	return 0;
}

