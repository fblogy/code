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
string s;
int n, l[N], r[N], a[N], p1, p2;
vector<pii> ans;
bool vis[N];
int main() {
//	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> s;
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, n+1) l[i] = i - 1;
	per(i, 1, n+1) r[i] = i + 1;
	priority_queue<pair<int, pii> > q;
	rep(i, 1, n) if (s[i-1] != s[i]) {
		q.push(mp(-abs(a[i] - a[i+1]), mp(-i, i+1)));
	}
	vis[0] = vis[n+1] = 1;
	while(!q.empty()) {
		auto tmp = q.top();
		q.pop();
		p1 = -tmp.se.fi; p2 = tmp.se.se;
		if (vis[p1] || vis[p2]) continue;
		ans.pb(mp(p1, p2));
		vis[p1] = vis[p2] = 1;
		p1 = l[p1]; p2 = r[p2];
		r[p1] = p2;
		l[p2] = p1;
		if (p1 > 0 && p1 <= n && p2 > 0 && p2 <= n && s[p1-1] != s[p2-1]) q.push(mp(-abs(a[p1] - a[p2]), mp(-p1, p2)));
	}
	cout << sz(ans) << endl;
	rep(i, 0, sz(ans)) cout << ans[i].fi << " " << ans[i].se << endl;
 	return 0;
}


