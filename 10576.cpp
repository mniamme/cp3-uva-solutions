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
int s, d;
int arr[14] = { 0 };
int mx = -1;
void rec(int nxt) {
	if (nxt > 12) {

		int j = 1;
		int sum = 0;
		int cnt = 0;
		MFOR(i,1,12)
		{
			if (arr[i] == s) {
				sum += arr[i];
			} else {
				sum -= arr[i];
			}
			if (i > 5) {
				if (arr[j] == s) {
					sum -= arr[j++];
				} else {
					sum += arr[j++];
				}
			}
			if (i >= 5) {
				if (sum < 0) {
					cnt++;
				}
			}
		}
		if (cnt == 8) {
			int tmp = 0;
			MFOR(i,1,12)
			{
//				cout << arr[i] << ' ';
				if (arr[i] == s) {
					tmp += arr[i];
				} else {
					tmp -= arr[i];
				}
			}
//			cout << " counter :" << cnt << " sum:" << tmp;
//			cout << endl;
			mx = max(mx, tmp);
		}
		return;
	}
	arr[nxt] = s;
	rec(nxt + 1);
	arr[nxt] = d;
	rec(nxt + 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	while (cin >> s >> d) {
		rec(1);
		if (mx < 0) {
			cout << "Deficit" << endl;
		} else {
			cout << mx << endl;
		}
		mx = -1;
	}
	return 0;
}

