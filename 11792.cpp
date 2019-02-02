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
	FOR(z, t)
	{
		int n;
		cin >> n;
		int h[10010], w[10010];
		FOR(i, n)
		{
			cin >> h[i];
		}
		FOR(i, n)
		{
			cin >> w[i];
		}
		int lw[10010] = { 0 }, dw[10010] = { 0 };
		int inc = 0, dec = 0;
		FOR(i, n)
		{
			// longest increasing subsequence
			int width = w[i];
			ROF(j, i)
			{
				if (h[j] < h[i]) {
					width = max(width, lw[j] + w[i]);
				}
			}
			lw[i] = width;
			inc = max(inc, width);

			// longest decreasing subsequence
			width = w[i];
			ROF(j, i)
			{
				if (h[j] > h[i]) {
					width = max(width, dw[j] + w[i]);
				}
			}
			dw[i] = width;
			dec = max(dec, width);
		}
		if (inc >= dec) {
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", z + 1, inc,
					dec);
		} else {
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", z + 1, dec,
					inc);
		}
	}
	return 0;
}

