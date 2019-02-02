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
	vector<string> in;
	string s;
	while (getline(cin, s)) {
		in.PB(s);
	}
	int n = atoi(in[0].c_str());
	int k = 2;
	vector<VI> input;
	FOR(i, n)
	{
		VI v;
		for (; k < SZ(in); k++) {
			if (in[k] == "") {
				k++;
				break;
			}
			v.PB(atoi(in[k].c_str()));
		}
		input.PB(v);
	}

	FOR(l, SZ(input))
	{
		if (l) {
			cout << endl;
		}
		int table[10010] = { 0 };
		int p[10010];
		table[0] = 1;
		p[0] = 0;
		int lis = 1;
		int l_end = 0;
		MFOR(i,1, SZ(input[l])-1)
		{
			int idx = i;
			int mx = 1;
			FOR(j, i)
			{
				if (input[l][j] < input[l][i] && table[j] + 1 > mx) {
					mx = table[j] + 1;
					idx = j;
				}
			}
			p[i] = idx;
			table[i] = mx;
			if (table[i] > lis) {
				lis = table[i];
				l_end = i;
			}
		}

		// extract lis
		VI v;
		int idx = l_end;
		while (true) {
			v.PB(input[l][idx]);
			if (p[idx] == idx) {
				break;
			}
			idx = p[idx];
		}
		cout << "Max hits: " << lis << endl;
		ROF(i, SZ(v))
		{
			cout << v[i] << endl;
		}

	}
	return 0;
}

