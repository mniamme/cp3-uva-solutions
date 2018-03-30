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

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif

	int k;
	while (cin >> k) {
		vector<pair<int, int> > ans;
		FORR(y,k+1,2*k)
		{
			ll temp1, temp2;
			temp1 = k * y;
			temp2 = y - k;
			ll x = temp1 / temp2;
			if ((x * y) / (x + y) == k && k * (x + y) == x * y) {
				ans.PB(MP(x, y));
			}
		}
		cout << SZ(ans) << endl;
		FOR(i,SZ(ans))
		{
			printf("1/%d = 1/%d + 1/%d\n", k, ans[i].F, ans[i].S);
		}
	}
	return 0;
}

