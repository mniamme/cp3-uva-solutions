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

struct in {
	int a;
	string s;
	int b;
};
vector<in> v;
bool can(double val) {
	double leak = 0;
	double cons = v[0].b / 100.0;
	double tank = val;
	MFOR(i,1,SZ(v)-1)
	{
		tank -= (v[i].a - v[i - 1].a) * (leak + cons);
		if (tank < 0) {
			return 0;
		}
		if (v[i].s == "Fuel") {
			cons = v[i].b / 100.0;
		}
		if (v[i].s == "Leak") {
			leak++;
		}
		if (v[i].s == "Mechanic") {
			leak = 0;
		}
		if (v[i].s == "Gas") {
			tank = val;
		}
	}
	return 1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	while (true) {
		int a, b;
		string s, ss;
		in tmp;
		cin >> a >> s;
		if (s == "Fuel") {
			cin >> ss >> b;
			if (b == 0) {
				return 0;
			}
		}
		if (s == "Gas") {
			cin >> ss;
		}
		tmp.a = a;
		tmp.s = s;
		tmp.b = b;
		v.PB(tmp);
		if (s == "Goal") {
			double lo, hi, mid, ans = 0;
			lo = 0, mid = 0;
			hi = 10000.0;
			while (fabs(hi - lo) > EPS) {
				mid = (lo + hi) / 2;
				if (can(mid)) {
					ans = mid;
					hi = mid;
				} else {
					lo = mid;
				}
			}
			printf("%.3f\n", ans);
			v.clear();
		}
	}
	return 0;
}

