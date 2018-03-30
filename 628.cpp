//the input constraints aren't clear in the description of the problem
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
int n;
vector<string> dic;
string rule;
void rec(int curr, string s) {
	if (curr == SZ(rule)) {
		cout << s << endl;
		return;
	}
	if (rule[curr] == '#') {
		FOR(i,SZ(dic))
		{
			rec(curr + 1, s + dic[i]);
		}
	} else {
		for (char i = '0'; i <= '9'; ++i) {
			rec(curr + 1, s + i);
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (cin >> n) {
		cout << "--" << endl;
		dic.clear();
		FOR(i,n)
		{
			string s;
			cin >> s;
			dic.PB(s);
		}
		int m;
		cin >> m;
		FOR(i,m)
		{
			string s;
			cin >> rule;
			rec(0, "");
		}
	}
	return 0;
}

