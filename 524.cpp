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
vector<VI> v(20, vector<int>());
bool vis[20] = { 0 };
VI tmp;
bool is_prime(int x) {
	MFOR(i,2,sqrt(x))
	{
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}
void rec(int curr) {
	if (SZ(tmp) == n && is_prime(tmp.front() + tmp.back())) {
		FOR(i,SZ(tmp))
		{
			cout << tmp[i];
			if (i != SZ(tmp) - 1) {
				cout << ' ';
			} else {
				cout << endl;
			}
		}
	}
	FOR(i,SZ(v[curr]))
	{
		if (vis[v[curr][i]]) {
			continue;
		}
		vis[v[curr][i]] = 1;
		tmp.PB(v[curr][i]);
		rec(v[curr][i]);
		vis[v[curr][i]] = 0;
		tmp.pop_back();
	}
}
void clear() {
	FILL(vis, 0);
	tmp.clear();
	MFOR(i,1,n)
	{
		v[i].clear();
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int t = 1;
	bool check = 0;
	while (cin >> n) {
		if (check) {
			cout << endl;
		}
		check = 1;
		MFOR(i,1,n)
		{
			MFOR(j,i+1,n)
			{
				if (is_prime(i + j)) {
					v[i].PB(j);
					v[j].PB(i);
				}
			}
		}
//		MFOR(i,1,n-1)
//		{
//			cout << i << " : ";
//			FOR(j,SZ(v[i]))
//			{
//				cout << v[i][j] << ' ';
//			}
//			cout << endl;
//		}
		tmp.PB(1);
		vis[1] = 1;
		printf("Case %d:\n", t++);
		rec(1);
		clear();

	}

	return 0;
}

