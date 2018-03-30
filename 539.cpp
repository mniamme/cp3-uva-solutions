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
vector<II> v;
bool vis[110] = { 0 };
int mx = 0;
vector<II> vtmp;
void rec(int curr, int no) {

	mx = max(mx, no);
	FOR(i,SZ(v))
	{
		if (!vis[i] && (v[i].F == curr || v[i].S == curr)) {
			vis[i] = 1;
			if (v[i].F == curr) {
				vtmp.PB(v[i]);
				rec(v[i].S, no + 1);
				mx = max(mx, SZ(vtmp));
				vtmp.pop_back();
			} else {
				vtmp.PB(v[i]);
				rec(v[i].F, no + 1);
				mx = max(mx, SZ(vtmp));
				vtmp.pop_back();
			}
			vis[i] = 0;
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (cin >> n >> m, n || m) {
		FOR(i,m)
		{
			int a, b;
			cin >> a >> b;
			v.PB(MP(a, b));
		}
		FOR(i,n)
		{
			FILL(vis, 0);
			vtmp.clear();
			rec(i, 0);
		}
		cout << mx << endl;
		v.clear();
		vtmp.clear();
		mx = 0;
	}
	return 0;
}

