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

const int N = 1e6 + 7;
vector<ll> d;
ll s[N], sum, ss, cc[N];
int a[N], n, x, f[100000];
vi g[N];
bool ok[N];

void dfs(int u) {
	s[u] = a[u];
	rep(i, 0, sz(g[u])) {
		int v = g[u][i];
		dfs(v);
		s[u] += s[v];
	}
}

unordered_map<ll, int> S;

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n+1) cin >> a[i], sum += a[i];
	rep(i, 2, n+1) cin >> x, g[x].pb(i);
	
	for (ll x = 1; x * x <= sum; x++) if (sum % x == 0) {
		d.pb(x);
		if (x * x != sum) d.pb(sum / x);
	}
	sort(all(d));
	
	dfs(1);
	rep(i, 0, sz(d)) S[d[i]] = i;
	
	rep(i, 1, n+1) cc[S[__gcd(sum, s[i])]] ++;
	
	rep(i, 0, sz(d))
		rep(j, i+1, sz(d)) if (d[j] % d[i] == 0) cc[i] += cc[j];
	rep(i, 0, sz(d)) {
		if (cc[i] == sum / d[i]) f[i] = 1, ok[i] = 1; 
		if (ok[i]) rep(j, 0, i) if (ok[j] && d[i] % d[j] == 0) f[i] = add(f[i], f[j]);
	}
	cout << f[sz(d)-1];
	return 0;
}


