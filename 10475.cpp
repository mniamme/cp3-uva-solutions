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
int t, p, s;
vector<string> topics;
vector<vector<string> > ans;
vector<pair<string, string> > prohibited;
vector<string> vtmp;
bool comp1(string &l, string &r) {
	if (SZ(l) < SZ(r)) {
		return 0;
	}
	if (SZ(l) > SZ(r)) {
		return 1;
	}
	if (SZ(l) == SZ(r)) {
		FOR(j,SZ(l))
		{
			if (l[j] > r[j]) {
				return 0;
			}
			if (l[j] < r[j]) {
				return 1;
			}
		}
	}
	return 0;
}
void rec1(int curr) {
	if (SZ(vtmp) == s) {
		FOR(i,SZ(prohibited))
		{
			bool a = 0, b = 0;
			FOR(j,SZ(vtmp))
			{
				if (vtmp[j] == prohibited[i].F) {
					a = 1;
					continue;
				}
				if (vtmp[j] == prohibited[i].S) {
					b = 1;
					continue;
				}
			}
			if (a && b) {
				return;
			}
		}
		vector<string> vtmp2(ALL(vtmp));
		sort(ALL(vtmp2), comp1);
		ans.PB(vtmp2);
		return;
	}
	if (curr == t) {
		return;
	}
	vtmp.PB(topics[curr]);
	rec1(curr + 1);
	vtmp.pop_back();
	rec1(curr + 1);
}
bool vis[110] = { 0 };
//void rec2(int curr) {
//	if (SZ(vtmp) == s) {
//		FOR(i,SZ(prohibited))
//		{
//			bool a = 0, b = 0;
//			FOR(j,SZ(vtmp))
//			{
//				if (vtmp[j] == prohibited[i].F) {
//					a = 1;
//					continue;
//				}
//				if (vtmp[j] == prohibited[i].S) {
//					b = 1;
//					continue;
//				}
//			}
//			if (a && b) {
//				return;
//			}
//		}
//		vector<string> vtmp2(ALL(vtmp));
//		sort(ALL(vtmp2), comp1);
//		ans.PB(vtmp2);
//		return;
//	}
//	if (curr == t) {
//		return;
//	}
//	MFOR(j,curr,t-1)
//	{
//		if (!vis[j]) {
//			vis[j] = 1;
//			vtmp.PB(topics[j]);
//			rec2(j + 1);
//			vis[j] = 0;
//			vtmp.pop_back();
//		}
//	}
//}
void clr() {
	topics.clear();
	ans.clear();
	prohibited.clear();
	vtmp.clear();
	FILL(vis, 0);
}
bool comp2(vector<string> &l, vector<string> &r) {
	FOR(i,SZ(l))
	{
		if (SZ(l[i]) < SZ(r[i])) {
			return 0;
		}
		if (SZ(l[i]) > SZ(r[i])) {
			return 1;
		}
		if (SZ(l[i]) == SZ(r[i])) {
			FOR(j,SZ(l[i]))
			{
				if (l[i][j] > r[i][j]) {
					return 0;
				}
				if (l[i][j] < r[i][j]) {
					return 1;
				}
			}
		}
	}
	return 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	int n;
	while (cin >> n) {
		int c = 1;
		FOR(z,n)
		{
			cin >> t >> p >> s;

			FOR(i,t)
			{
				string stmp;
				cin >> stmp;
				FOR(j,SZ(stmp))
				{
					if (islower(stmp[j])) {
						stmp[j] = toupper(stmp[j]);
					}
				}
				topics.PB(stmp);
			}
			FOR(i,p)
			{
				string tmpa, tmpb;
				cin >> tmpa >> tmpb;
				FOR(j,SZ(tmpa))
				{
					if (islower(tmpa[j])) {
						tmpa[j] = toupper(tmpa[j]);
					}
				}
				FOR(j,SZ(tmpb))
				{
					if (islower(tmpb[j])) {
						tmpb[j] = toupper(tmpb[j]);
					}
				}
				prohibited.PB(MP(tmpa, tmpb));
			}
			rec1(0);
//			rec2(0);
			sort(ALL(ans), comp2);
			printf("Set %d:\n", c++);
			FOR(i,SZ(ans))
			{
				FOR(j,SZ(ans[i]))
				{
					cout << ans[i][j];
					if (j != SZ(ans[i]) - 1) {
						cout << ' ';
					}
				}
				cout << endl;
			}

			clr();
			cout << endl;
		}
	}
	return 0;
}

