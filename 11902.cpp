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
int n;
vector<VI> adj(110);
bool init_vis[110] = { 0 };
bool vis[110] = { 0 };
int skip;

void dfs(int u) {
	init_vis[u] = 1;
//	cout << u << ' ';
	FOR(i,SZ(adj[u]))
	{
		int v = adj[u][i];
		if (!init_vis[v]) {
			dfs(v);
		}
	}
}
void dfs1(int u) {
//	cout << u << ' ';
	vis[u] = 1;
	FOR(i,SZ(adj[u]))
	{
		int v = adj[u][i];
		if (!vis[v] && v != skip) {
			dfs1(v);
		}
	}
}

void println() {
	cout << '+';
	FOR(i,2*n-1)
	{
		cout << '-';
	}
	cout << '+' << endl;

}
void clr() {
	FOR(i,n)
	{
		adj[i].clear();
	}
	FILL(init_vis, 0);
	FILL(vis, 0);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	int c = 1;
	int t;
	cin >> t;
	FOR(z,t)
	{
		cin >> n;
		FOR(i,n)
		{
			FOR(j,n)
			{
				int tmp;
				cin >> tmp;
				if (tmp) {
					adj[i].PB(j);
				}
			}
		}

		char ans[110][110];
		FILL(ans, 'N');
		dfs(0);
		FOR(i,n)
		{
			if (init_vis[i]) {
				ans[0][i] = 'Y';
			}
//			cout << i << ' ' << init_vis[i] << endl;
		}

		MFOR(i,1,n-1)
		{
			skip = i;
			FILL(vis, 0);
			dfs1(0);
			FOR(j,n)
			{
				if (!vis[j] && init_vis[j]) {
					ans[i][j] = 'Y';
				}
			}
		}

		printf("Case %d:\n", c++);
		println();
		FOR(i,n)
		{
			cout << '|';
			FOR(j,n)
			{
				cout << ans[i][j] << '|';
			}
			cout << endl;
			println();
		}
		clr();
	}

	return 0;
}

