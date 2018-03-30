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
int adj[50010];
bool vis[50010];
int len[50010];
int dfs(int u) {
	vis[u] = 1;
	int tmp = 0;
	if (!vis[adj[u]]) {
		tmp = 1 + dfs(adj[u]);
	}
	vis[u] = 0;
	len[u] = tmp;
	return len[u];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	FOR(z,t)
	{
		FILL(adj, -1);
		FILL(len, -1);
		FILL(vis, 0);
		int n;
		cin >> n;
		FOR(i,n)
		{
			int a, b;
			cin >> a >> b;
			adj[a] = b;
		}
		int ans, mx = 0;
		MFOR(i,1,n)
		{
			if (len[i] == -1) {
				dfs(i);
			}
			if (len[i] > mx) {
				mx = len[i];
				ans = i;
			}
		}

		printf("Case %d: %d\n", z + 1, ans);
	}

}

