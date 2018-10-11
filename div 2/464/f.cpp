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

int f[105][N][2];
int n, k, l[N], r[N], kk, d, pr, l1, r1, l2, r2, pos[N], pos2[N];

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
		l1 = 0, r1 = -1;
		l2 = 0, r2 = -1;
		rep(j, 0, r[i]+1) {
			int &x = f[i][j][0], &y = f[i][j][1];
			pr=min(r[i] - l[i], j);
			while (r1 >= l1 && pos[l1] < j - pr) l1++;
			while (r1 >= l1 && f[i-1][j][1] <= f[i-1][pos[r1]][1]) r1--;
			pos[++r1] = j;
			x = min(x, f[i-1][pos[l1]][1] + 1);
			y = min(y, f[i-1][pos[l1]][1] + 2);
			y = min(y, f[i-1][j][1]);
			while (r2 >= l2 && pos2[l2] < j - d - pr) l2++;
			if (j - d >= 0) while (r2 >= l2 && f[i-1][j - d][0] <= f[i-1][pos2[r2]][0]) r2--;
			if (j - d >= 0) pos2[++r2] = j - d;
			if (l2 <= r2) {
				x = min(x, f[i-1][pos2[l2]][0] + 2);
				y = min(y, f[i-1][pos2[l2]][0] + 1);
			}
			if (j - d - (r[i] - l[i]) >= 0 ) x = min(x, f[i-1][j - d - (r[i] - l[i])][0]);
		}
	}
	if (f[kk][n][0] <= n*3 || f[kk][n][1] <= n*3) {
		cout << "Full" << endl << min(f[kk][n][0], f[kk][n][1]);
	}else cout << "Hungry";
	return 0;
}

