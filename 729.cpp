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
int n, h;
vector<string> v;
void rec(string s, int ones, int length) {
	if (length > n) {
		return;
	}
	if (ones == h && length == n) {
		v.PB(s);
		return;
	}
	rec(s + '0', ones, length + 1);
	rec(s + '1', ones + 1, length + 1);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	FOR(z,t)
	{
		cin >> n >> h;
		rec("", 0, 0);
		FOR(i,SZ(v))
		{
			cout << v[i] << endl;
		}
		if (z < t - 1) {
			cout << endl;
		}
		v.clear();
	}
	return 0;
}

