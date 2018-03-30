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
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c;
	cin >> c;
	FOR(z,c)
	{
		int p;
		cin >> p;
		VI an;
		FOR(i,p+1)
		{
			int x;
			cin >> x;
			an.PB(x);
		}
		int d, k;
		cin >> d >> k;

		int e = 1;
		int count = 1;

		while (true) {
			if (k >= e && k <= e + (d * count) - 1) {
				break;
			}
			e = e + (d * count);
			count++;
		}

		vector<LL> new_an;
		int i = 1;
		while (true) {
			LL tmp = 0;
			FOR(j,p+1)
			{
				tmp += an[j] * pow(i, j);
			}
			new_an.PB(tmp);
			if (i == count) {
				break;
			}
			i++;
		}
		cout << new_an[count - 1] << endl;

	}
	return 0;
}

