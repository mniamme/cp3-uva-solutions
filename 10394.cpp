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
#define F first
#define S second
#define FILL(a,v) memset(a,v,sizeof(a))

typedef long long LL;
/*************************************************/

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	vector<bool> sieve(20000001, true);
	sieve[0] = sieve[1] = 0;
	for (int i = 2; i * i <= 20000000; ++i) {
		if (sieve[i])
			for (int j = i * i; j <= 20000000; j += i) {
				sieve[j] = 0;
			}
	}
	vector<pair<int, int> > v;
	int temp = 2;

	for (int i = 3; i <= 20000000; ++i) {
		if (sieve[i]) {
			if (i - temp == 2) {
				v.PB(MP(temp, i));
			}
			temp = i;
		}
	}
	int s;
	while (cin >> s) {
		printf("(%d, %d)\n", v[s - 1].F, v[s - 1].S);
	}
	return 0;

}

