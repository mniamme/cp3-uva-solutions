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
	bool ch = 0;
	while (cin >> n, n) {
		if (ch) {
			cout << endl;
		}
		ch = 1;
		bool check = 0;
		MFOR(i,1234,98765/n)
		{
			int tmp = i * n;
			int flag = 0;
			if (i < 10000) {
				flag = 1;
			}
			int tmp2 = i;
			while (tmp2) {
				flag |= 1 << (tmp2 % 10);
				tmp2 /= 10;
			}
			tmp2 = tmp;
			while (tmp2) {
				flag |= 1 << (tmp2 % 10);
				tmp2 /= 10;
			}
			if (flag == (1 << 10) - 1) {
				printf("%0.5d / %0.5d = %d\n", tmp, i, n);
				check = 1;
			}
		}
		if (!check) {
			printf("There are no solutions for %d.\n", n);
		}
	}

	return 0;
}

