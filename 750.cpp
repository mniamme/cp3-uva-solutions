//the most fucking output format i have ever seen
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
vector<vector<pair<int, int> > > sol;
vector<pair<int, int> > queen;
bool valid(int r, int c) {
	FOR(i,SZ(queen))
	{
		int tmp1, tmp2;
		tmp1 = abs(queen[i].F - r);
		tmp2 = abs(queen[i].S - c);
		if (tmp1 == tmp2) {
			return false;
		}
	}
	return true;
}
bool vis[9] = { 0 };
void chess(int row) {
	if (row > 8) {
		sol.PB(queen);
		return;
	}
	for (int c = 1; c <= 8; ++c) {
		if (vis[c] == 1 || !valid(row, c)) {
			continue;
		}
		vis[c] = 1;
		queen.PB(MP(row, c));
		chess(row + 1);
		queen.pop_back();
		vis[c] = 0;
	}
}

bool comp(pair<int, int> first, pair<int, int> second) {
	if (first.F < second.F) {
		return 1;
	}
	return 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	chess(1);
	int t;
	cin >> t;
	string s;
	FOR(i,t)
	{
		int a, b;
		getline(cin, s);
		cin >> a >> b;
		vector<vector<pair<int, int> > > ans;
		pair<int, int> ptmp = MP(a, b);
		FOR(j,SZ(sol))
		{
			bool check = 0;
			vector<pair<int, int> > vtmp;
			FOR(k,SZ(sol[j]))
			{
				if (sol[j][k] == ptmp) {
					check = 1;
				}
				vtmp.PB(MP(sol[j][k].S, sol[j][k].F));
			}
			if (check) {
				ans.PB(vtmp);
			}
		}
		vector<vector<int> > fans;
		FOR(j,SZ(ans))
		{
			sort(ALL(ans[j]), comp);
			vector<int> vtmp;
			FOR(k,SZ(ans[j]))
			{
				vtmp.PB(ans[j][k].S);
			}
			fans.PB(vtmp);
		}
		sort(ALL(fans));
		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
		FOR(j,SZ(fans))
		{
			printf("%2d      ", j + 1);
			FOR(k,SZ(fans[j]))
			{
				cout << fans[j][k];
				if (k != SZ(fans[j]) - 1) {
					cout << ' ';
				}
			}
//			if (j != SZ(fans) - 1) {
			cout << endl;
//			}
		}
		if (i != t - 1) {
			cout << endl;
		}
	}
	return 0;
}

