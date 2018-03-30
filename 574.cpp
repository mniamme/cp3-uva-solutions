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
int t, n;
int arr[13];
set<vector<int> > ans;
vector<int> tmp;
void rec(int curr, int rem) {
	if (rem == 0) {
		sort(ALLR(tmp));
		ans.insert(tmp);
		return;
	}
	if (curr == n || rem < 0) {
		return;
	}
	tmp.PB(arr[curr]);
	rec(curr + 1, rem - arr[curr]);
	tmp.pop_back();
	rec(curr + 1, rem);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
	while (cin >> t) {
		cin >> n;
		FOR(i,n)
		{
			cin >> arr[i];
		}
		if (n != 0) {
			rec(0, t);
			set<vector<int> >::iterator it;
			if (SZ(ans) == 0) {
				printf("Sums of %d:\n", t);
				cout << "NONE" << endl;
			} else {
				printf("Sums of %d:\n", t);
				vector<vector<int> > temp(ALL(ans));
				ROF(i,SZ(ans))
				{
					cout << temp[i][0];
					MFOR(j,1,SZ(temp[i])-1)
					{
						cout << '+' << temp[i][j];
					}
					cout << endl;
				}
			}
		}
		ans.clear();
		tmp.clear();
	}
	return 0;
}

