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
	int n;
	while (cin >> n) {
		int arr[3010];
		FOR(i,n)
		{
			cin >> arr[i];

		}
		map<int, int> mp;
		MFOR(i,1,n-1)
		{
			mp[i] = 1;
		}
		bool check = 0;
		MFOR(i,1,n-1)
		{
			if (!mp[abs(arr[i] - arr[i - 1])]) {
				check = 1;
				break;
			} else {
				mp[abs(arr[i] - arr[i - 1])] = 0;
			}
		}
		if (check) {
			cout << "Not jolly" << endl;
		} else {
			cout << "Jolly" << endl;
		}
	}
	return 0;
}

