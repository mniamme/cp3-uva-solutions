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
struct order {
	int x;
	int y;
	int p;
};
bool comp(const order &l, const order &r) {
	if (l.x < r.x) {
		return 1;
	}
	if (l.x == r.x && l.y < r.y) {
		return 1;
	}
	return 0;
}
int n, b, o;
vector<order> orders;
int mx;
int asc[10] = { 0 };
int des[10] = { 0 };
void rec(int curr, int cost) {
	mx = max(mx, cost);
	if (curr == o) {
		return;
	}

	int cap = 0;
	MFOR(i,0,orders[curr].x)
	{
		cap += asc[i];
		cap -= des[i];
	}
	if (cap + orders[curr].p <= n) {
		asc[orders[curr].x] += orders[curr].p;
		des[orders[curr].y] += orders[curr].p;
		rec(curr + 1,
				cost + ((orders[curr].y - orders[curr].x) * orders[curr].p));
		asc[orders[curr].x] -= orders[curr].p;
		des[orders[curr].y] -= orders[curr].p;
	}
	rec(curr + 1, cost);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (cin >> n >> b >> o, n || b || o) {
		orders.clear();
		FILL(asc, 0);
		FILL(des, 0);
		FOR(i,o)
		{
			int x, y, p;
			order tmp;
			cin >> x >> y >> p;
			tmp.x = x;
			tmp.y = y;
			tmp.p = p;
			orders.PB(tmp);
		}
		sort(ALL(orders), comp);
		mx = 0;
		rec(0, 0);
		cout << mx << endl;
	}
}

