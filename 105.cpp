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
	int l, h, r;
	int arr[10005] = { 0 };
	while (cin >> l >> h >> r) {
		MFOR(i,l+1,r-1)
		{
			if (h > arr[i]) {
				arr[i] = h;
			}
		}
	}
//	FOR(i,30)
//	{
//		cout << i << ' ';
//	}
//	cout << endl;
//	FOR(i,30)
//	{
//		cout << arr[i] << ' ';
//	}
	VI path;
	MFOR(i,1,10001)
	{
		if (arr[i] > arr[i - 1]) {
			path.PB(i - 1);
			path.PB(arr[i]);
		} else if (arr[i] < arr[i - 1]) {
			path.PB(i);
			path.PB(arr[i]);
		}
	}
	FOR(i,SZ(path))
	{
		cout << path[i];
		if (i != SZ(path) - 1) {
			cout << ' ';
		}
	}
	cout << endl;
	return 0;
}


