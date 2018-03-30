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

typedef long long ll;
/*************************************************/
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

/*the correct solution for the problem is in this line
 * No subset of a series is allowed.
 * For example, a series of
 * five uni-distant primes having even four of them in the interval  is not allowed,
 * all the  five primes should be in the interval.
 */


	bitset<32001> sieve;
	vector<vector<int> > distances;

	//sieve

	vector<int> primes;
	sieve.set();
	sieve[0] = 0;
	sieve[1] = 0;
	for (int i = 2; i * i <= 32000; ++i) {
		if (sieve[i]) {
			for (int j = i * i; j <= 32000; j += i) {
				sieve[j] = 0;
			}
		}
	}
	FOR(i,32001)
	{
		if (sieve[i]) {
			primes.PB(i);
		}
	}
	for (int i = 0; i < SZ(primes) - 2; ++i) {
		vector<int> v;
		v.PB(primes[i]);
		v.PB(primes[i + 1]);
		int t = primes[i + 1] - primes[i];
		i += 2;
		while (primes[i] - primes[i - 1] == t) {
			v.PB(primes[i]);
			i++;
		}
		if (SZ(v) >= 3) {
			distances.PB(v);
		}
		i -= 2;
	}
//	FOR(i,SZ(distances))
//	{
//		FOR(j,SZ(distances[i]))
//		{
//			cout << distances[i][j];
//			if (j < SZ(distances[i]) - 1) {
//				cout << ' ';
//			}
//		}
//		cout << endl;
// }

	int x, y;
	while (cin >> x >> y, x || y) {
// swap trick
		if (x > y) {
			swap(x, y);
		}

		FOR(i,SZ(distances))
		{
			if (distances[i].front() >= x && distances[i].back() <= y) {
				FOR(j,SZ(distances[i]))
				{
					cout << distances[i][j];
					if (j == SZ(distances[i]) - 1) {
						cout << endl;
					} else {
						cout << ' ';
					}
				}
			}
		}
	}
	return 0;

}


