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
void addArrays(int result[], int tempr[]) {
	int carry = 0;
	int temp;
	FOR(i, 510)
	{
		temp = result[i] + tempr[i] + carry;
		result[i] = temp % 10;
		carry = temp / 10;
	}
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	string s1, s2;

	while (cin >> s1) {
		cin >> s2;
		if (SZ(s2) < SZ(s1)) {
			swap(s1, s2);
		}
		reverse(ALL(s1));
		reverse(ALL(s2));
		int x[510] = { 0 }, y[510] = { 0 };
		FOR(i, SZ(s1))
		{
			x[i] = s1[i] - '0';
		}
		FOR(i, SZ(s2))
		{
			y[i] = s2[i] - '0';
		}
		int result[510] = { 0 };
		FOR(i, SZ(s1))
		{
			int carry = 0;
			int temp;
			int tempr[510] = { 0 };
			FOR(j, SZ(s2) + 1)
			{
				temp = x[i] * y[j] + carry;
				tempr[j + i] = temp % 10;
				carry = temp / 10;
			}
			addArrays(result, tempr);
		}
		bool check = 0;
		ROF(i, 510)
		{
			if (result[i] == 0 && check == 0) {
				continue;
			}
			check = 1;
			cout << result[i];
		}
		if (check == 0) {
			cout << 0;
		}
		cout << endl;
	}
	return 0;
}

