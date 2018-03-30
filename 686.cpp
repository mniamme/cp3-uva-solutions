#include <bits/stdc++.h>

using namespace std;

#define SZ(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define ALLR(v) v.rbegin(),v.rend()
#define FN(s,c) (int)s.find(c)
#define FOR(i,e) for (int i = 0; i < e; i++)
#define FORR(i,s) for (int i = s-1; i >= 0; i--)
#define IT(it,v) for(it=v.begin();it!=v.end();it++)
#define ITT(it,v) for(it=v.rbegin();it!=v.rend();it++)
#define PB push_back
#define MP make_pair
#define f first
#define s second
#define FILL(a,v) memset(a,v,sizeof(a))

typedef long long LL;
/*************************************************/

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	while (cin >> n, n) {
		int temp = 1 << 15;
		vector<bool> sieve(temp + 1, true);
		sieve[0] = sieve[1] = 0;
		for (int i = 2; i * i <= temp; ++i) {
			if (sieve[i]) {
				for (int j = i * i; j <= temp; j += i) {
					sieve[j] = 0;
				}
			}
		}
		int c = 0;
		FOR(i,n+1)
		{
			if (sieve[i] && sieve[n - i]) {
				c++;
				sieve[n - i] = 0;
			}
		}
		cout << c << endl;
	}
	return 0;

}

