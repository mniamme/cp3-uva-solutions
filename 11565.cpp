#include <bits/stdc++.h>

using namespace std;

#define SZ(v) (int)v.size()
#define ALL(v) v.begin(),v.end()
#define ALLR(v) v.rbegin(),v.rend()
#define FN(s,c) (int)s.find(c)
#define FOR(i,e) for (int i = 0; i < e; i++)
#define FORR(i,s,e) for (int i = s; i <= e; i++)
#define ROF(i,s) for (int i = s-1; i >= 0; i--)
#define IT(v,it) for(it=v.begin();it!=v.end();it++)
#define ITT(v,it) for(it=v.rbegin();it!=v.rend();it++)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FILL(a,v) memset(a,v,sizeof(a))

typedef long long ll;
/*************************************************/
void print(int x, int y, int z) {
	int mx = max(x, max(y, z));
	int mn = min(x, min(y, z));
	int mid = x + y + z - mx - mn;
	cout << mn << ' ' << mid << ' ' << mx << endl;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "a", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		bool check = 0;
//from the cp3 book we can change the range to 100 so it will take less operations than this code and than the book
		FORR(i,1,10000)
		{                
			FORR(j,i+1,10000-i)
			{
				int x, y, z;
				x = i;
				y = j;
				z = a - (x + y);
				if (x * y * z == b && x * x + y * y + z * z == c && z != y
						&& z != x) {
					print(x, y, z);
					check = 1;
					break;
				} else {
					y = -j;
					z = a - (x + y);
					if (x * y * z == b && x * x + y * y + z * z == c && z != y
							&& z != x) {
						print(x, y, z);
						check = 1;
						break;
					} else {
						x = -i;
						y = j;
						z = a - (x + y);
						if (x * y * z == b && x * x + y * y + z * z == c
								&& z != y && z != x) {
							print(x, y, z);
							check = 1;
							break;
						} else {
							y = -j;
							z = a - (x + y);
							if (x * y * z == b && x * x + y * y + z * z == c
									&& z != y && z != x) {
								print(x, y, z);
								check = 1;
								break;
							}
						}
					}
				}
			}
			if (check) {
				break;
			}
		}
		if (!check) {
			cout << "No solution." << endl;
		}
	}
	return 0;
}

