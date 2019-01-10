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
	int a, b, c;
	cin >> t;
	LL arr[30][30][30];
	LL sum[30][30][30];
	FOR(z, t)
	{
		FILL(sum, 0);
		cin >> a >> b >> c;
		MFOR(i, 1, a)
		{
			MFOR(j, 1, b)
			{
				MFOR(k, 1, c)
				{
					cin >> arr[i][j][k];
				}
			}
		}

		// max 2D range sum trick
		// for each level the cell (i, j) will contain the sum of the sub array from (i, j) to (0, 0)
		MFOR(lvl, 1, a)
		{
			// initial row and column
			MFOR(row, 1, b)
			{
				sum[lvl][row][1] = arr[lvl][row][1] + sum[lvl][row - 1][1];
			}
			MFOR(col, 1, c)
			{
				sum[lvl][1][col] = arr[lvl][1][col] + sum[lvl][1][col - 1];
			}
			MFOR(row, 2, b)
			{
				MFOR(col, 2, c)
				{
					sum[lvl][row][col] = arr[lvl][row][col]
							+ sum[lvl][row - 1][col] + sum[lvl][row][col - 1]
							- sum[lvl][row - 1][col - 1];
				}
			}
		}

		LL mx = -1000000000000000;
		LL curr_sum = 0;

		// try all possible sub rectangle
		MFOR(row, 1, b)
		{
			MFOR(col, 1, c)
			{
				MFOR(i, row, b)
				{
					MFOR(j, col, c)
					{
						curr_sum = 0;
						// max. sum sub levels
						MFOR(lvl, 1, a)
						{
							curr_sum += sum[lvl][i][j] - sum[lvl][row - 1][j]
									- sum[lvl][i][col - 1]
									+ sum[lvl][row - 1][col - 1];
							mx = max(mx, curr_sum);
							if (curr_sum < 0) {
								curr_sum = 0;
							}
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

