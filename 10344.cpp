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
vector<vector<char> > per;
vector<char> vtmp;
void rec() {
	if (SZ(vtmp) == 4) {
		per.PB(vtmp);
		return;
	}
	vtmp.PB('+');
	rec();
	vtmp.pop_back();
	vtmp.PB('-');
	rec();
	vtmp.pop_back();
	vtmp.PB('*');
	rec();
	vtmp.pop_back();

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	rec();
	int a, b, c, d, e;
	while (cin >> a >> b >> c >> d >> e, a || b || c || d || e) {
		VI v;
		v.PB(a);
		v.PB(b);
		v.PB(c);
		v.PB(d);
		v.PB(e);
		bool check = 0;
		sort(ALL(v));
		FOR(i,SZ(per))
		{
			int sum = v[0];
			FOR(j,4)
			{
				if (per[i][j] == '+') {
					sum += v[j + 1];
				} else if (per[i][j] == '-') {
					sum -= v[j + 1];
				} else {
					sum *= v[j + 1];
				}
			}
			if (sum == 23) {
				check = 1;
				break;
			}
		}
		if (check == 1) {
			cout << "Possible" << endl;
			continue;
		}
		while (next_permutation(ALL(v))) {
			FOR(i,SZ(per))
			{
				int sum = v[0];
				FOR(j,4)
				{
					if (per[i][j] == '+') {
						sum += v[j + 1];
					} else if (per[i][j] == '-') {
						sum -= v[j + 1];
					} else {
						sum *= v[j + 1];
					}
				}
				if (sum == 23) {
					check = 1;
					break;
				}
			}
			if (check == 1) {
				break;
			}
		}
		if (check == 1) {
			cout << "Possible" << endl;
		} else {
			cout << "Impossible" << endl;
		}
	}

	return 0;
}


