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
struct maker {
	string s;
	int lo;
	int hi;
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	FOR(z,t)
	{
		vector<maker> v;
		int n;
		cin >> n;
		maker tmp;
		FOR(i,n)
		{
			cin >> tmp.s >> tmp.lo >> tmp.hi;
			v.PB(tmp);
		}

		int q;
		cin >> q;

		FOR(i,q)
		{
			int x;
			cin >> x;
			string s;
			int cnt = 0;
			FOR(j,SZ(v))
			{
				if (x >= v[j].lo && x <= v[j].hi) {
					cnt++;
					s = v[j].s;
				}
			}
			if (cnt == 1) {
				cout << s << endl;
			} else {
				cout << "UNDETERMINED" << endl;
			}
		}
		if (z != t - 1) {
			cout << endl;
		}
	}

	return 0;
}

