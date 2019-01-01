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
int p[1010];
int w[1010];
int table[1010][35];
int dp_top_down(int n, int curr, int s) {
	if (s < 0) {
		return -30100;
	}
	if (table[curr][s] != -1) {
		return table[curr][s];
	}
	if (curr == n) {
		return 0;
	}
	return table[curr][s] = max(dp_top_down(n, curr + 1, s),
			p[curr] + dp_top_down(n, curr + 1, s - w[curr]));
}
int dp_bottom_up(int n, int s) {

	// initialize the table
	FILL(table, 0);
	MFOR(j, w[0], s)
	{
		table[0][j] = p[0];
	}

	MFOR(j, 1, n-1)
	{
		FOR(k, s+1)
		{
			if (k < w[j]) {
				table[j][k] = table[j - 1][k];
			} else {
				table[j][k] = max(table[j - 1][k],
						p[j] + table[j - 1][k - w[j]]);
			}
		}
	}
	return table[n - 1][s];
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	FOR(z, t)
	{
		// comment the next line before using bottom-up solution
		FILL(table, -1);

		int n;
		cin >> n;
		FOR(i, n)
		{
			cin >> p[i];
			cin >> w[i];
		}
		int g, s;
		cin >> g;
		LL sum = 0;

		// construct the table for bottom-up solution
		// comment the next line before using top-down solution
		// dp_bottom_up(n, 30);

		FOR(i, g)
		{
			cin >> s;

			// bottom-up solution
			// sum += table[n - 1][s];

			// top-down solution
			sum += dp_top_down(n, 0, s);
		}
		cout << sum << endl;
	}
	return 0;
}

