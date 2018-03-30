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
int n, m;
int s;
char arr[10][10];
vector<string> v;
string word = "IEHOVA";
int curr = 0;
void search(int i, int j) {
	if (curr == 6) {
		if (arr[i - 1][j] == '#' && i - 1 >= 0) {
			v.PB("forth");
		} else if (arr[i][j + 1] == '#' && j + 1 < m) {
			v.PB("right");
		} else if (arr[i][j - 1] == '#' && j - 1 >= 0) {
			v.PB("left");
		}
		return;
	}
	if (arr[i - 1][j] == word[curr]) {
		v.PB("forth");
		curr++;
		search(i - 1, j);
	} else if (arr[i][j + 1] == word[curr] && j + 1 < m) {
		v.PB("right");
		curr++;
		search(i, j + 1);
	} else if (arr[i][j - 1] == word[curr] && j - 1 >= 0) {
		v.PB("left");
		curr++;
		search(i, j - 1);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	FOR(z,t)
	{
		v.clear();
		curr = 0;
		cin >> n >> m;
		FOR(i,n)
		{
			FOR(j,m)
			{
				cin >> arr[i][j];
				if (arr[i][j] == '@') {
					s = j;
				}
			}
		}
		search(n - 1, s);
		FOR(i,SZ(v))
		{
			cout << v[i];
			if (i < SZ(v) - 1) {
				cout << ' ';
			}
		}
		cout << endl;

	}
	return 0;
}

