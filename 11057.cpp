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

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//binary search solution
	int n;
	while (cin >> n) {
		VI v;
		FOR(i,n)
		{
			int x;
			cin >> x;
			v.PB(x);
		}
		int m;
		cin >> m;
		II ans;
		int mn = INT_MAX;
		sort(ALL(v));
		FOR(i,SZ(v))
		{
			if (v[i] < m) {
				int lo = i + 1;
				int hi = SZ(v) - 1;
				int mid;
				bool check = 0;
				while (lo <= hi) {
					mid = (lo + hi) / 2;
					if (v[mid] > m - v[i]) {
						hi = mid - 1;
					} else if (v[mid] < m - v[i]) {
						lo = mid + 1;
					} else {
						check = 1;
						break;
					}
				}
				if (abs(v[i] - v[mid]) < mn && check) {
					ans = MP(v[i], v[mid]);
					mn = abs(v[i] - v[mid]);
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",
				min(ans.F, ans.S), max(ans.F, ans.S));
	}
	return 0;
}

// iterative solution

//int n;
//	while (cin >> n) {
//		VI v;
//		FOR(i,n)
//		{
//			int x;
//			cin >> x;
//			v.PB(x);
//		}
//		int m;
//		cin >> m;
//		II ans;
//		int mn = INT_MAX;
//		FOR(i,n)
//		{
//			MFOR(j,i+1,n-1)
//			{
//				if (v[i] + v[j] == m && abs(v[i] - v[j]) < mn) {
//					ans = MP(v[i], v[j]);
//					mn = abs(v[i] - v[j]);
//				}
//			}
//		}
//		printf("Peter should buy books whose prices are %d and %d.\n\n",
//				min(ans.F, ans.S), max(ans.F, ans.S));
//	}

