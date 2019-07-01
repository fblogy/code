#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
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

const int N = 2e4 + 7;
const int P = 1e9 + 7;

int l1, r1, l, r, mid, p, pp, n, k, m;
ll dp[505][N], a[N], c[N], d[N], b[N];

struct node{
	ll x, y;
	node(ll x = 0, ll y = 0): x(x), y(y) {};
} h[N];

bool check(const node &a, const node &b, const node &c){
	return (c.y - b.y) * (b.x - a.x) > (b.y - a.y) * (c.x - b.x);
}

bool check2(const node &a, const node &b, ll w){
	return (b.y - a.y) < (b.x - a.x) * w;
}

int main(){
//	freopen("a.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	rep(i, 1, n+1) cin >> a[i] >> d[i] >> c[i];
	rep(i, 1, k+1) cin >> b[i], m = max(1ll * m, b[i]);
	rep(i, 1, m+1) if (i <= c[1]) dp[1][i] = a[1] * i - d[1] * (i - 1) * i / 2;else dp[1][i] = pw(60);
	rep(t, 2, n+1) {
		rep(i, 0, m+1) dp[t][i] = pw(60);
		for (int j = 0; j <= m; j += c[t]) {
			l = 1; r = 0;
			rep(i, j, min(int(j + c[t]), m + 1)) {
				if (dp[t-1][i] != pw(60)) {
					node tmp(i, 2 * dp[t-1][i] - (2 * a[t] + d[t]) * i - d[t] * i * i);
					while (l < r && !check(h[r-1], h[r], tmp)) r--;
					h[++r] = tmp;
				}
				p = h[r].x;
				if (l <= r) {
					l1 = l; r1 = r - 1;
					while (l1 <= r1) {
						mid = l1 + r1 >> 1;
						if (!check2(h[mid], h[mid+1], - 2 * d[t] * i)) {
							p = h[mid].x; r1 = mid - 1;
						}else l1 = mid + 1;
					}
					dp[t][i] = min(dp[t][i], dp[t-1][p] + a[t] * (i - p) - d[t] * (i - p -1) * (i - p) / 2);
				}
				
			}
			l = 1; r = 0;
			per(i, max(0ll, j - c[t]), j+1) {
				if (dp[t-1][i] != pw(60)) {
					node tmp(i, 2 * dp[t-1][i] - (2 * a[t] + d[t]) * i - d[t] * i * i);
					while (l < r && check(h[r-1], h[r], tmp)) r--;
					h[++r] = tmp;
				}
				p = h[r].x; pp = i + c[t];
				if (pp > m) continue;
				if (l <= r) {
					l1 = l; r1 = r - 1;
					while (l1 <= r1) {
						mid = l1 + r1 >> 1;
						if (!check2(h[mid], h[mid+1], - 2 * d[t] * pp)) {
							p = h[mid].x; r1 = mid - 1;
						}else l1 = mid + 1;
					}
					dp[t][pp] = min(dp[t][pp], dp[t-1][p] + a[t] * (pp - p) - d[t] * (pp - p -1) * (pp - p) / 2);
				}	
			} 
		}
	}
	rep(i, 1, k+1) cout << dp[n][b[i]] << endl;
	return 0;
}

