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
VI adj[15];
int n, m;
VI vtmp;
bool vis[15] = { 0 };
bool check = 0;
void backtrack(int u, int length) {
	vtmp.PB(u);
	vis[u] = 1;
	if (length == m) {
		check = 1;
		cout << '(';
		FOR(i,SZ(vtmp))
		{
			cout << vtmp[i];
			if (i < SZ(vtmp) - 1) {
				cout << ',';
			} else {
				cout << ')' << endl;
			}
		}

		return;
	}
	FOR(v,SZ(adj[u]))
	{
		if (!vis[adj[u][v]]) {
			backtrack(adj[u][v], length + 1);
			vtmp.pop_back();
			vis[adj[u][v]] = 0;
		}
	}

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (cin >> n) {
		if (n == -9999) {
			cout << endl;
			continue;
		}
		FOR(i,15)
		{
			adj[i].clear();
		}
		FILL(vis, 0);
		vtmp.clear();
		check = 0;
		cin >> m;
		FOR(i,n)
		{
			FOR(j,n)
			{
				int x;
				cin >> x;
				if (x == 1) {
					adj[i + 1].PB(j + 1);
				}
			}
		}
		backtrack(1, 0);
		if (!check) {
			cout << "no walk of length " << m << endl;
		}
	}
	return 0;
}

