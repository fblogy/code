// 根据p[i-1] * a[i] = p[i] (%m) 有解条件gcd(p[i-1], m) | p[i] 建图，相同gcd缩点，求DAG最长链，用exgcd求方案。 
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
int n, m, x, y, f[N], use[N], ne[N];
vi a, ans, w[N], d[N];
void dfs(int x) {
	if (f[x] != -1) return;
	f[x] = sz(w[x]);
	for (auto y : d[x]) {
		//de(y);
		dfs(y);
		if (f[x] == -1 || f[x] < f[y] + sz(w[x])) f[x] = f[y] + sz(w[x]), ne[x] = y;
	}
}

void exgcd(ll a,ll b,ll &x,ll &y){
    if(b == 0){
        x = 1; y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

int get(int a, int b) {
	ll x, y;
	exgcd(a, m, x, y);
	x *= b / (__gcd(a, m));
	x %= m;
	if (x < 0) x += m;
	return x;
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	memset(f, -1, sizeof(f));
	rep(i, 1, n+1) {
		cin >> x; use[x] = 1;
	}
	rep(i, 1, m) if (!use[i]) w[__gcd(i, m)].pb(i);
	rep(i, 1, m) for (int j = i + i; j <= m; j += i) d[j].pb(i);
	dfs(m); 
	int now = m;
	while (ne[now]) {
		now = ne[now];
		for (auto v : w[now]) a.pb(v);
	}
	reverse(all(a));
	rep(i, 0, sz(a)) {
		if (i == 0) ans.pb(a[0]);
		else ans.pb(get(a[i-1], a[i]));
	}
	//rep(i, 0, sz(a)) de(a[i]);
	if (!use[0]) ans.pb(0);
	cout << sz(ans) << endl;
	for (auto u : ans) cout << u << " ";
	return 0;
}


