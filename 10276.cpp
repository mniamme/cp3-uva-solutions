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
	int t;
	cin >> t;
	FOR(z,t)
	{
		VI v[51];
		int n;
		cin >> n;
		int curr = 1;
		while (true) {
			int c = curr;
			FOR(i,n)
			{
				if (SZ(v[i]) == 0) {
					v[i].PB(curr++);
					break;
				} else {
					int tmp, root;
					tmp = v[i].back() + curr;
					root = sqrt(tmp);
					if (root * root == tmp) {
						v[i].PB(curr++);
						break;
					}
				}
			}
			if (curr == c) {
				int sum = 0;
				FOR(i,n)
				{
					sum += SZ(v[i]);
				}
				cout << sum << endl;
				break;
			}
		}
	}
	return 0;
}


