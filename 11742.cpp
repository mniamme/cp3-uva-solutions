#include <bits/stdc++.h>

using namespace std;

#define SZ(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define ALLR(v) v.rbegin(),v.rend()
#define FN(s,c) (int)s.find(c)
#define FOR(i,e) for (int i = 0; i < e; i++)
#define FORR(i,s,e) for (int i = s; i <= e; i++)
#define ROF(i,s) for (int i = s-1; i >= 0; i--)
#define ROFF(i,s,e) for (int i = s; i >= e; i--)
#define IT(v,it) for(it=v.begin();it!=v.end();it++)
#define ITT(v,it) for(it=v.rbegin();it!=v.rend();it++)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FILL(a,v) memset(a,v,sizeof(a))

typedef long long ll;
/*************************************************/
bool check(vector<pair<pair<int, int>, int> > v, int arr[], int n) {
	FOR(i,SZ(v))
	{
		int f, s;
		FOR(j,n)
		{
			if (arr[j] == v[i].F.F) {
				f = j;
			}
			if (arr[j] == v[i].F.S) {
				s = j;
			}
		}
		int temp = abs(f - s);
		if (v[i].S < 0) {
			if (temp < abs(v[i].S)) {
				return 0;
			}
		} else {
			if (temp > abs(v[i].S)) {
				return 0;
			}
		}
	}
	return 1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	while (cin >> n >> m, n || m) {
		vector<pair<pair<int, int>, int> > v;
		FOR(i,m)
		{
			int a, b, c;
			cin >> a >> b >> c;
			v.PB(MP(MP(a, b), c));
		}
		int arr[10];
		FOR(i,n)
		{
			arr[i] = i;
		}
		int c = check(v, arr, n);
		while (next_permutation(arr, arr + n)) {
			c += check(v, arr, n);
		}
		cout << c << endl;
	}
	return 0;
}

