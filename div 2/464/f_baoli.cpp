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
//---

const int N=100005;
const int mod=1e9+7;

int f[200][1000][2];
int n, k, l[N], r[N], kk, d;

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> kk;
	rep(i, 1, kk + 1) cin >> l[i] >> r[i];
	if (r[kk] != 2 * n) {kk++; l[kk] = r[kk] = n * 2;}
	memset(f,10,sizeof(f));
	f[0][0][0] = 0;
	rep(i, 1, kk + 1) {
		d = l[i] - r[i-1];
		rep(j, 0, n+1) 
			rep(k, 0, min(r[i] - l[i], j) + 1) {
				int &x = f[i][j][0];
				if (j - k - d >= 0)
					x = min(x, f[i-1][j - k - d][0] + (k != r[i] - l[i]) * 2);
				if (j - k >= 0)
					x = min(x, f[i-1][j - k][1] + 1);
				int &y = f[i][j][1];
				if (j - k >= 0)
					y = min(y, f[i-1][j - k][1] + (k != 0) * 2);
				if (j - k - d >= 0)
					y = min(y, f[i-1][j - k - d][0] + 1);
			}
	}
	/*rep(i, 1, kk+1)
		rep(j, 0, n+1) dd(i),dd(j),dd(f[i][j][0]),de(f[i][j][1]);*/
	if (f[kk][n][0] <= n*3 || f[kk][n][1] <= n*3) {
		cout << "Full" << endl << min(f[kk][n][0], f[kk][n][1]);
	}else cout << "Hungry";
	return 0;
}

