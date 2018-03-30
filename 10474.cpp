//binary search solution O(nlogn)

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
	int n, q;
	int c = 1;
	while (cin >> n >> q, n && q) {
		VI v1, v2;
		int tmp;
		FOR(i,n)
		{
			cin >> tmp;
			v1.PB(tmp);
		}
		FOR(i,q)
		{
			cin >> tmp;
			v2.PB(tmp);
		}
		sort(ALL(v1));
		printf("CASE# %d:\n", c++);
		FOR(i,SZ(v2))
		{
			int ans = -1;
			int low = 0, high = n - 1, mid;
			while (low <= high) {
				mid = low + (high - low) / 2;
				if (v1[mid] < v2[i]) {
					low = mid + 1;
				} else if (v1[mid] > v2[i]) {
					high = mid - 1;
				} else {
					ans = mid;
					high = mid - 1;
				}
			}
			if (ans == -1) {
				printf("%d not found\n", v2[i]);
			} else {
				printf("%d found at %d\n", v2[i], ans + 1);
			}
		}
	}
	return 0;
}


//linear search solution O(n^2)

//	int n, q;
//	int c = 1;
//	while (cin >> n >> q, n && q) {
//		VI v1, v2;
//		FOR(i,n)
//		{
//			int tmp;
//			cin >> tmp;
//			v1.PB(tmp);
//
//		}
//		FOR(i,q)
//		{
//			int tmp;
//			cin >> tmp;
//			v2.PB(tmp);
//		}
//		sort(ALL(v1));
//		printf("CASE# %d:\n", c++);
//		FOR(i,SZ(v2))
//		{
//			int check = -1;
//			FOR(j,SZ(v1))
//			{
//				if (v1[j] == v2[i]) {
//					check = j + 1;
//					break;
//				}
//			}
//			if (check != -1) {
//				printf("%d found at %d\n", v2[i], check);
//			} else {
//				printf("%d not found\n", v2[i]);
//			}
//		}
//	}
