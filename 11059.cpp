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
	int n;
	int c = 1;
	while (cin >> n) {
		int arr[18];
		FOR(i,n)
		{
			cin >> arr[i];
		}
		LL ans = 0;
		FOR(i,n)
		{
			LL res = arr[i];
			ans = max(ans, res);
			MFOR(j,i+1,n-1)
			{
				res *= arr[j];
				ans = max(ans, res);
			}

		}
		printf("Case #%d: The maximum product is %lld.\n\n", c++, ans);
	}
	return 0;
}


