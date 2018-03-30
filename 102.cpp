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

pair<int, string> fun(int arr[], vector<vector<int> > in) {
	int moves = 0;
	FOR(i,3)
	{
		FOR(j,3)
		{
			if (j == arr[i]) {
				continue;
			}
			moves += in[i][j];
		}
	}
	string s = "BGC", r = "";
	FOR(i,3)
	{
		r += s[arr[i]];
	}
	return MP(moves, r);
}
bool comp(pair<int, string> f, pair<int, string> s) {
	if (f.F < s.F) {
		return 1;
	}
	if (f.F == s.F && f.S < s.S) {
		return 1;
	}
	return 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	int n1, n2, n3, n4, n5, n6, n7, n8, n9;
	while (cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6 >> n7 >> n8 >> n9) {
		vector<vector<int> > in(4, vector<int>());
		in[0].PB(n1);
		in[0].PB(n2);
		in[0].PB(n3);
		in[1].PB(n4);
		in[1].PB(n5);
		in[1].PB(n6);
		in[2].PB(n7);
		in[2].PB(n8);
		in[2].PB(n9);

		int arr[] = { 0, 1, 2 };
		vector<pair<int, string> > ans;
		ans.PB(fun(arr, in));
		while (next_permutation(arr, arr + 3)) {
			ans.PB(fun(arr, in));
		}
		sort(ALL(ans), comp);
		cout << ans[0].S << ' ' << ans[0].F << endl;
	}
	return 0;
}

