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

typedef long long ll;
/*************************************************/
int arr[9];
int row[9];
bool vis[9] = { 0 };
int mn;
bool valid(int r, int c) {
	FOR(i,c)
	{
		if (abs(row[i] - r) == abs(c - i)) {
			return 0;
		}
	}
	return 1;
}
void chess(int c) {
	if (c == 8) {
		int cnt = 0;
		FOR(i,8)
		{
			if (arr[i] - 1 != row[i]) {
				cnt++;
			}
		}

		mn = min(mn, cnt);
		return;
	}
	FOR(r,8)
	{
		if (vis[r] || !valid(r, c)) {
			continue;
		}
		vis[r] = 1;
		row[c] = r;
		chess(c + 1);
		vis[r] = 0;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	int t = 1;
	int in;
	while (cin >> in) {
		FILL(row, 0);
		FILL(vis, 0);
		mn = INT_MAX;

		arr[0] = in;
		MFOR(i,1,7)
		{
			cin >> arr[i];
		}
		chess(0);
		printf("Case %d: %d\n", t++, mn);
	}
	return 0;
}

