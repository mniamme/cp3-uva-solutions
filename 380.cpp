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
int arr[10000][20000];
bool vis[10000] = { 0 };
int rec(int number, int time) {
	if (vis[number]) {
		return 9999;
	}
	if (arr[number][time] == -1) {
		return number;
	}
	vis[number] = 1;
	return rec(arr[number][time], time);

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
//	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	cout << "CALL FORWARDING OUTPUT" << endl;
	FOR(z,n)
	{
		cout << "SYSTEM " << z + 1 << endl;
		FILL(arr, -1);
		string s;
		while (getline(cin, s)) {
			if (s == "0000") {
				break;
			}
			istringstream iss(s);
			int a, b, c, d;
			iss >> a >> b >> c >> d;
			MFOR(i,b,b+c)
			{
				arr[a][i] = d;
			}
		}
		while (getline(cin, s)) {
			if (s == "9000") {
				break;
			}
			istringstream iss(s);
			int a, b;
			iss >> a >> b;
			FILL(vis, 0);
			printf("AT %04d CALL TO %04d RINGS %04d\n", a, b, rec(b, a));
		}
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}

