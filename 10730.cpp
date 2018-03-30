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
	while (cin >> n, n) {
		char c;
		cin >> c;
		int arr[10010];
		int vis[10010] = { 0 };
		FOR(i,n)
		{
			cin >> arr[i];
			vis[arr[i]] = i + 1;
		}
		bool check = 0;
		FOR(i,n-2)
		{
			MFOR(j,i+1,n-2)
			{

				int tmp = arr[i] - arr[j];
				tmp *= -1;
				if (arr[j] + tmp < 0||arr[j]+tmp>10000) {
					continue;
				}
				if (vis[arr[j] + tmp] != 0 && vis[arr[j] + tmp] > j + 1) {
					check = 1;
					break;
				}
			}
			if (check) {
				break;
			}
		}
		if (check) {
			cout << "no" << endl;
		} else {
			cout << "yes" << endl;
		}
	}
	return 0;
}

