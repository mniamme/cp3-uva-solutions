//recursive solution
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

typedef long long ll;
/*************************************************/
int c;
int n;
int arr[22];
vector<int> v;
int mn;
vector<int> ans;
void cd(int i, int length) {
	if (length < 0) {
		return;
	}
	if (i == c) {
		if (length < mn) {
			mn = length;
			ans = v;
		}

		return;
	}

	v.PB(arr[i]);
	cd(i + 1, length - arr[i]);
	v.pop_back();
	cd(i + 1, length);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	while (cin >> n) {
		mn = n;
		cin >> c;
		FOR(i,c)
		{
			cin >> arr[i];
		}
		cd(0, n);
		FOR(i,SZ(ans))
		{
			cout << ans[i] << ' ';
		}
		cout << "sum:" << n - mn << endl;
	}


	return 0;
}
//iterative solution
//
//	int n, c;
//	while (cin >> n) {
//		int arr[22];
//		cin >> c;
//		FOR(i,c)
//		{
//			cin >> arr[i];
//		}
//		int mx = 0;
//		vector<int> ans, v;
//		MFOR(i,1,(1<<c)-1)
//		{
//			int sum = 0;
//			FOR(j,c)
//			{
//				if (i & (1 << j)) {
//					v.PB(arr[j]);
//					sum += arr[j];
//				}
//			}
//			if (sum <= n) {
//				if (sum > mx) {
//					ans = v;
//					mx = sum;
//				}
//			}
//			v.clear();
//		}
//
//		FOR(i,SZ(ans))
//		{
//			cout << ans[i] << ' ';
//		}
//		cout << "sum:" << mx << endl;
//	}
