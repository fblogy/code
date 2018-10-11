#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;
//---

const int N=1005;
const int mod=1e9+7;

int n, m, x, y;
bool f[N][N];

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int w;
	cin >> n >> m >> x >> y; w = y;
	
	f[x][y] = 1;
	if (x != 1) {cout << 1 << " " << y << endl;f[1][y] = 1;}
	while (y >= 1) {
		if (!f[1][y]) f[1][y] = 1,cout << 1 << " " << y << endl;
		y--;
	}
	y = 1;
	while (y <= m) {
		if (!f[1][y]) cout << 1 << " " << y << endl, f[1][y] = 1;
		y++;
	}
	rep(i, 2, n+1) {
		if ((i%2 == 0) ^ (w == m)) {
			y = m;
			while (y >= 1) {
				if (!f[i][y]) f[i][y] = 1,cout << i << " " << y << endl;
				y--;
			}
		}else {
			y = 1;
			while (y <= m) {
				if (!f[i][y]) cout << i << " " << y << endl, f[i][y] = 1;
				y++;
			}
		}
	} 
	return 0;
}

