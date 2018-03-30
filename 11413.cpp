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
int calc(int x) {
	int cont = 1;
	int ves = x;
	FOR(i,SZ(v))
	{
		if (v[i] > x) {
			return -1;
		}
		if (v[i] <= ves) {
			ves -= v[i];
		} else {
			cont++;
			ves = x - v[i];
		}

	}
	return cont;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	while (cin >> n >> m) {
		FOR(i,n)
		{
			int x;
			cin >> x;
			v.PB(x);
		}
		int lo, hi, mid, ans;
		lo = 0;
		hi = 1e9;
		mid = 0;
		while (lo < hi) {
			mid = lo + (hi - lo) / 2;
			if (calc(mid) == -1) {
				lo = mid + 1;
			} else if (calc(mid) > m) {
				lo = mid + 1;
			} else if (calc(mid) <= m) {
				hi = mid;
				ans = mid;
			}
		}
		cout << ans << endl;
		v.clear();
	}
	return 0;
}

