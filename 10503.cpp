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
int n, m;
vector<II> in;
II ans[20];
bool vis[20] = { 0 };
bool rec(int nxt, int taken) {
	if (taken == n) {
//		FOR(i,n+2)
//		{
//			cout << '[' << ans[i].F << ',' << ans[i].S << "] ";
//		}
//		cout << endl;
		return 1;
	}

	FOR(i,SZ(in))
	{
		II tmp1 = MP(in[i].S, in[i].F), tmp2;
		int tmp3 = ans[nxt - 1].S;
		if (vis[i] || (in[i].F != tmp3 && tmp1.F != tmp3)) {
			continue;
		}
		if (in[i].F == tmp3) {
			tmp2 = in[i];
		} else {
			tmp2 = tmp1;
		}
		if (taken == n - 1 && tmp2.S != ans[nxt + 1].F) {
			continue;
		}
		ans[nxt] = tmp2;
		vis[i] = 1;
		if (rec(nxt + 1, taken + 1)) {
			return 1;
		}
		vis[i] = 0;
	}
	return 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	while (cin >> n, n) {
		cin >> m;
		int a, b;
		cin >> a >> b;
		ans[0] = MP(a, b);
		cin >> a >> b;
		ans[n + 1] = MP(a, b);
		FOR(i,m)
		{
			cin >> a >> b;
			in.PB(MP(a, b));
		}
		if (rec(1, 0)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		in.clear();
		FILL(vis, 0);
	}
	return 0;
}

