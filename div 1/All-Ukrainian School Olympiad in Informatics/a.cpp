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

const int N = 5e4 + 7;
int n, m, u, v, f[N], G, S, g, s;
ll ans;

int get(int x) {  return x == f[x] ? x : f[x] = get(f[x]);} 

struct node{
	int u, v, g, s;
} edge[N];

bool cmp(node a, node b) {return a.g < b.g;}

vector<node> tmp;
vector<node> solve(vector<node> tmp){
	vector<node> res;
	rep(i, 1, n + 1) f[i] = i;
	rep(i, 0, sz(tmp)) {
		u = get(tmp[i].u), v = get(tmp[i].v);
		if (u != v) {
			f[u] = v;
			res.pb(tmp[i]);
		}
	}
	return res;
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m >> G >> S;
	rep(i, 1, m+1) cin >> u >> v >> g >> s, edge[i] = {u, v, g, s};
	sort(edge+1, edge+m+1, cmp);
	ans = pw(62);
	rep(i, 1, m+1) {
		tmp.pb(edge[i]);
		per(i, 1, sz(tmp)) if (tmp[i].s < tmp[i-1].s) swap(tmp[i], tmp[i-1]);
		tmp = solve(tmp);
		if (sz(tmp) == n-1) ans = min(ans, 1ll * G * edge[i].g + 1ll * S * tmp.back().s);
	}
	if (ans == pw(62)) cout << -1;else cout << ans;
	return 0;
}


