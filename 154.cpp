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
	string s;
	char c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;
	vector<vector<string> > v;
	while (cin >> c1, c1 != '#') {
		/////////////////////input
		if (c1 == 'e') {
			int mn = INT_MAX;
			int ans;
			FOR(i,SZ(v))
			{
				int tmp = 0;

				FOR(j,SZ(v))
				{
					if (i == j) {
						continue;
					}
					FOR(k,5)
					{
						if (v[j][k] != v[i][k]) {
							tmp++;
						}
					}
				}
				if (tmp < mn) {
					mn = tmp;
					ans = i + 1;
				}
			}
			cout << ans << endl;

//			FOR(i,SZ(v))
//			{
//				FOR(j,SZ(v[i]))
//				{
//					cout << v[i][j] << ' ';
//				}
//				cout << endl;
//			}
//			cout << endl;
			v.clear();
			cin >> c1;
			if (c1 == 'c') {
				cin >> s;
				continue;
			} else {
				goto comp;
			}
		}
		comp: scanf("/%c,%c/%c,%c/%c,%c/%c,%c/%c", &c2, &c3, &c4, &c5, &c6, &c7,
				&c8, &c9, &c10);
		vector<string> vtmp;
		string s1 = "", s2 = "", s3 = "", s4 = "", s5 = "";
		s1 += c1;
		s1 += c2;
		s2 += c3;
		s2 += c4;
		s3 += c5;
		s3 += c6;
		s4 += c7;
		s4 += c8;
		s5 += c9;
		s5 += c10;
		vtmp.PB(s1);
		vtmp.PB(s2);
		vtmp.PB(s3);
		vtmp.PB(s4);
		vtmp.PB(s5);
		sort(ALL(vtmp));
		v.PB(vtmp);
		/////////////////////////////

	}

	return 0;
}

