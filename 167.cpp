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
int chess_scores[9][9];
bool col[9] = { 0 }, rd[16] = { 0 }, ld[16] = { 0 };
int mx = -1;
void chess(int r, int sum) {
	if (r == 8) {
		mx = max(mx, sum);
		return;
	}
	FOR(c,8)
	{
		if (col[c] || rd[r + c] || ld[r - c + 7]) {
			continue;
		}
		col[c] = rd[r + c] = ld[r - c + 7] = 1;
		chess(r + 1, sum + chess_scores[r][c]);
		col[c] = rd[r + c] = ld[r - c + 7] = 0;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	int k;
	cin >> k;
	FOR(z,k)
	{
		FOR(i,8)
		{
			FOR(j,8)
			{
				cin >> chess_scores[i][j];
			}
		}

		chess(0, 0);
		printf("%5d\n", mx);
		FILL(col, 0);
		FILL(rd, 0);
		FILL(ld, 0);
		mx = -1;
	}
	return 0;
}

