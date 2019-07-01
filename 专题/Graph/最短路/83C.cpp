//求最短路且字典序最小，应该先分层，之后对每一层求重新定rank 
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 51;
int ans2, n, m, k, use[1000], d[N][N];
string ans, a[N], ss[N][N];
queue<pii> q;
pii s, t;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void solve() {
	//if (use['b'] == 1 && use['c'] == 1) de(1);
	memset(d, 0, sizeof(d));
	q.push(s);d[s.fi][s.se] = 1;ss[t.fi][t.se] = "S";
	while (!q.empty()) {
		auto tmp = q.front(); q.pop();
		int x = tmp.fi, y = tmp.se;
		//if (use['b'] == 1 && use['c'] == 1)dd(x),de(y);
		rep(i, 0, 4) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx > n || xx < 1 || yy > m || yy < 1 || !use[a[xx][yy]]) continue;
			if (xx == t.fi && yy == t.se) {
				if (!d[xx][yy]) d[xx][yy] = d[x][y] + 1;
				if (d[xx][yy] != d[x][y] + 1) continue;
				if (ss[xx][yy] == "S") ss[xx][yy] = ss[x][y];else
				ss[xx][yy] = min(ss[xx][yy], ss[x][y]);
				continue;
			}
			if (!d[xx][yy]) {
				d[xx][yy] = d[x][y] + 1;
				ss[xx][yy] = ss[x][y] + a[xx][yy];
				q.push(mp(xx, yy)); 
			}else if (d[xx][yy] == d[x][y] + 1) ss[xx][yy] = min(ss[x][y] + a[xx][yy], ss[xx][yy]); 
		}
	}
	//if (use['b'] == 1 && use['c'] == 1) de(d[t.fi][t.se]);
	if (d[t.fi][t.se] == 0) return;
	if (d[t.fi][t.se] < ans2) {
		ans2 = d[t.fi][t.se];
		ans = ss[t.fi][t.se];
	}
	if (d[t.fi][t.se] > ans2) return;
	ans = min(ans, ss[t.fi][t.se]);
}

void dfs(int d, int now) {
	if (d == k+1) {
		solve();
		return;
	}
	rep(i, now, 'z'+1) {
		use[i] = 1;
		dfs(d+1, i+1);
		use[i] = 0;
	}
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m >> k;
	rep(i, 1, n+1) cin >> a[i], a[i] = " " + a[i];
	rep(i, 1, n+1) rep(j, 1, m+1) if (a[i][j] == 'S') s = mp(i, j);
	else if (a[i][j] == 'T') t = mp(i, j);
	use['T'] = 1;
	ans2 = pw(30);
	ans = "S";
	dfs(1, 'a');
	if (ans == "S") cout << -1;else cout << ans;
	return 0;
}


