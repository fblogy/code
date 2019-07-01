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
//----

const int P = 1e7 + 7;
const int BSZ = 333, N = 1e5 + 7;
int bn, bl[N], br[N], id[N], op, l, r, n, q, L[N], R[N], now[N];
vector<ll> V;
pair<pii, int> Q[N];
ll sum, k, ans[N], a[N];
//unordered_map<ll, int> cnt;
int cnt[N*2];
void ini(int n) {
  bn = (n - 1) / BSZ + 1;
  rep(b, 0, bn) {
    bl[b] = b * BSZ;
    br[b] = min(n, (b + 1) * BSZ);
    rep(i, bl[b], br[b]) id[i] = b;
  }
}

bool cmp(pair<pii, int> a, pair<pii, int> b) {
	if (id[a.fi.fi] != id[b.fi.fi]) return a.fi.fi < b.fi.fi;
	return a.fi.se < b.fi.se;
}

void ADD(int x, int op) {
	if (op) {if (L[x] != -1) sum += cnt[L[x]];}
	else {if (R[x] != -1) sum += cnt[R[x]];}
	cnt[now[x]]++;
}

void DEL(int x, int op) {
	cnt[now[x]]--;
	if (op) {if (L[x] != -1) sum -= cnt[L[x]];}
	else {if (R[x] != -1) sum -= cnt[R[x]];}
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> k;
	rep(i, 1, n+1) {
		cin >> op;
		if (op == 1) a[i] = 1;else a[i] = -1;
	}
	rep(i, 1, n+1) {
		cin >> op;
		a[i] *= op;
	}
	rep(i, 1, n+1) a[i] += a[i-1];
	rep(i, 0, n+1) V.pb(a[i]);
	sort(all(V));
	V.erase(unique(all(V)), V.end());
	rep(i, 0, n+1) {
		L[i] = lower_bound(all(V), a[i] - k) - V.begin();
		if (L[i] == sz(V) || V[L[i]] != a[i] - k) L[i] = -1;
		R[i] = lower_bound(all(V), a[i] + k) - V.begin();
		if (R[i] == sz(V) || V[R[i]] != a[i] + k) R[i] = -1;
		now[i] = lower_bound(all(V), a[i]) - V.begin();
	}
	ini(n+1);
	cin >> q;
	rep(i, 0, q) cin >> Q[i].fi.fi >> Q[i].fi.se, Q[i].se = i, Q[i].fi.fi--; 
	sort(Q, Q+q, cmp);
	l = r = 0; cnt[now[0]]++; sum = 0; 
	rep(i, 0, q) {
		while (r < Q[i].fi.se) ADD(++r, 1);
		while (l > Q[i].fi.fi) ADD(--l, 0);
		while (r > Q[i].fi.se) DEL(r--, 1);
		while (l < Q[i].fi.fi) DEL(l++, 0);
		ans[Q[i].se] = sum;
	}
	rep(i, 0, q) cout << ans[i] << endl;
	return 0;
}


