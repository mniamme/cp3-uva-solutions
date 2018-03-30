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
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	int k;
	int n;
	cin >> n;
	FOR(i,n)
	{
		cin >> k;
		bool check = 0;
		vector<int> v;
		for (int a = 0; a * a <= k; a++) {
			for (int b = a; b * b <= k - (a * a); b++) {
				int c = sqrt(k - (a * a) - (b * b));
				if (a * a + b * b + c * c == k) {
					int tmp1, tmp2, tmp3;
					tmp1 = a + b + c;
					tmp2 = min(a, min(b, c));
					tmp3 = max(a, max(b, c));
					cout << tmp2 << ' ' << tmp1 - tmp2 - tmp3 << ' ' << tmp3
							<< endl;
					check = 1;
					break;
				}
			}
			if (check) {
				break;
			}
		}
		if (!check) {
			cout << -1 << endl;
		}
	}
	return 0;
}

