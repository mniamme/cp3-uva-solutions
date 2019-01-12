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

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	getline(cin, s);

	int arr[30][30];
	FOR(z, t)
	{
		int r = 0, c = 0;
		while (getline(cin, s)) {
			if (s.empty()) {
				break;
			}
			c = 0;
			FOR(i, SZ(s))
			{
				if (s[i] == '1') {
					arr[r][c++] = 1;
				} else {
					arr[r][c++] = 0;
				}
			}
			r++;
		}
		FOR(i, r)
		{
			FOR(j, c)
			{
				if (i > 0) {
					arr[i][j] += arr[i - 1][j];
				}
				if (j > 0) {
					arr[i][j] += arr[i][j - 1];
				}
				if (i > 0 && j > 0) {
					arr[i][j] -= arr[i - 1][j - 1];
				}
			}
		}

		int mx = 0;
		FOR(i, r)
		{
			FOR(j, c)
			{
				MFOR(k, i, r-1)
				{
					MFOR(l, j, c-1)
					{
						int sum = arr[k][l];
						if (i > 0) {
							sum -= arr[i - 1][l];
						}
						if (j > 0) {
							sum -= arr[k][j - 1];
						}
						if (i > 0 && j > 0) {
							sum += arr[i - 1][j - 1];
						}
						if (sum == (k - i + 1) * (l - j + 1)) {
							mx = max(mx, sum);
						}
					}
				}
			}
		}
		cout << mx << endl;
		if (z < t - 1) {
			cout << endl;
		}
	}
	return 0;
}

