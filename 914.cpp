#include <bits/stdc++.h>

using namespace std;

#define SZ(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define ALLR(v) v.rbegin(),v.rend()
#define FN(s,c) (int)s.find(c)
#define FOR(i,e) for (int i = 0; i < e; i++)
#define FORR(i,s) for (int i = s-1; i >= 0; i--)
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
#endif
	bitset<1000001> sieve;
	sieve.set();
	sieve[0] = 0;
	sieve[1] = 0;
	for (int i = 2; i * i <= 1000000; ++i) {
		if (sieve[i]) {
			for (int j = i * i; j <= 1000000; j += i) {
				sieve[j] = 0;
			}
		}
	}
	int t;
	cin >> t;
	FOR(i,t)
	{
		int l, u;
		cin >> l >> u;
		int champ[80000] = { 0 };
		vector<int> primes;

		for (int j = l; j <= u; ++j) {
			if (sieve[j]) {
				primes.PB(j);
			}
		}
//		FOR(j,SZ(primes))
//		{
//			cout << primes[j] << ' ';
//		}
		if (SZ(primes) < 2) {
			cout << "No jumping champion" << endl;
			continue;
		}
		int mx = -1;
		for (int j = 1; j < SZ(primes); ++j) {
			champ[primes[j] - primes[j - 1]]++;
			mx = max(mx, primes[j] - primes[j - 1]);
		}

		int c = 0;
		int mx2 = -1;
		int ans;

		FOR(j,mx+1)
		{
			if (champ[j]) {
//				cout << j << ' ' << champ[j] << endl;
				if (champ[j] > mx2) {
					mx2 = champ[j];
					c = 0;
					ans = j;
				} else if (champ[j] == mx2) {
					c++;
				}
			}
		}
		if (!c) {
			cout << "The jumping champion is " << ans << endl;
		} else {
			cout << "No jumping champion" << endl;

		}
	}
	return 0;

}


