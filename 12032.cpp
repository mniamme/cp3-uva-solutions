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
#define EPS 1e-9

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> II;
/*************************************************/
vector<int> v;
bool can(int k) {
	MFOR(i,1, SZ(v)-1)
	{
		if (v[i] - v[i - 1] > k) {
			return 0;
		} else if (v[i] - v[i - 1] == k) {
			k--;
		}
	}
	return 1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	FOR(z,t)
	{
		v.PB(0);
		int n;
		cin >> n;
		FOR(i,n)
		{
			int x;
			cin >> x;
			v.PB(x);
		}
		int lo = 0, hi = 1e7, mid = 0, ans = 0;
		while (lo < hi) {
			mid = lo + (hi - lo) / 2;
			if (can(mid)) {
				hi = mid;
				ans = mid;
			} else {
				lo = mid + 1;
			}
		}
		printf("Case %d: %d\n", z + 1, ans);
		v.clear();
	}
	return 0;
}

