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

const int N = 2e5 + 7;
int p[5], n, m, t, st[5], l, r, mid, c[N], ma, n1, n2, cnt[N], x, k, w;
ll ans, sum, num;
ll s[5][N];
vi v[5];

void check(int mid) {
	sum = num = 0;
	rep(i, 1, 4) {
		p[i] = upper_bound(all(v[i]), mid) - v[i].begin();//, st[i]);
		p[i] = max(p[i], st[i]);
		sum += s[i][p[i]];
		num += p[i];
	} 
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m >> k;
	rep(i, 1, n+1) cin >> c[i], ma = max(ma, c[i]);
	cin >> n1;
	rep(i, 1, n1+1) {
		cin >> x;
		cnt[x] += 1;
	}
	cin >> n2;
	rep(i, 1, n2+1) {
		cin >> x;
		cnt[x] += 2;
	}
	rep(i, 1, n+1) {
		if (cnt[i] == 0) v[3].pb(c[i]);
		else if (cnt[i] == 3) v[0].pb(c[i]);
		else if (cnt[i] == 1) v[1].pb(c[i]);
		else v[2].pb(c[i]);
	} 
	rep(i, 0, 4) {
		sort(all(v[i]));
		rep(j, 1, sz(v[i]) + 1) s[i][j] = s[i][j-1] + v[i][j-1];
	}
	//rep(i, 0, 4) dd(s[i][1]);
	ans = pw(60);
	rep(i, 0, sz(v[0]) + 1) {
		t = max(k - i, 0);
		st[1] = st[2] = t;
		if (t + t + i > m) continue;
		if  (sz(v[1]) < t || sz(v[2]) < t) continue;
		l = 0; r = ma; w = -1;
		while (l < r) {
			mid = l + r >> 1;
			check(mid);
			if (num < m - i) l = mid + 1;
			else  {
				//w = mid;
				r = mid;
			}
		}
		//if (w != -1) {
		check(l);
		if (num >= m - i) ans = min(ans, s[0][i] + sum - l * max(0ll, (num - (m - i))));
		check(r);
		if (num >= m - i) ans = min(ans, s[0][i] + sum - r * max(0ll, (num - (m - i))));
		//}
	}
	if (ans == pw(60)) cout << -1;else cout << ans;
	return 0;
}


