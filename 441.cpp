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
	int k;
	bool check = 0;
	while (cin >> k) {
		if (k == 0) {
			break;
		}
		if (check) {
			cout << endl;
		}
		check = 1;

		int arr[15];
		FOR(i,k)
		{
			cin >> arr[i];
		}
		sort(arr, arr + k);
		for (int i = 0; i < k - 5; ++i) {
			for (int j = i + 1; j < k - 4; ++j) {
				for (int l = j + 1; l < k - 3; ++l) {
					for (int m = l + 1; m < k - 2; ++m) {
						for (int n = m + 1; n < k - 1; ++n) {
							for (int o = n + 1; o < k; ++o) {
								printf("%d %d %d %d %d %d\n", arr[i], arr[j],
										arr[l], arr[m], arr[n], arr[o]);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}


