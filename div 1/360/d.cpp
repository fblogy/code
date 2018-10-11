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

const int N = 1e3 + 7;
int fa[N * 2], n, m, q, u, v, w, L, R;
pair<pii, int> edge[N * N / 2];
vi tmp;

int get(int x) {return x == fa[x] ? x : fa[x] = get(fa[x]);}

struct Seg{
#define ls (now << 1)
#define rs (ls | 1) 
	static const int N = 5e5 + 7;
	vi tr[N * 4];
	
	bool solve(int id, int now) {
		int u, v;
		u = edge[id].fi.fi; v = edge[id].fi.se;
		if (get(u) == get(v)) {
			tr[now].pb(id);
			return 1;
		}else {
			int t1 = get(u), t2 = get(v + n);
			if (t1 == t2) return 0;
			tr[now].pb(id);
			fa[t1] = t2;
			t1 = get(u + n); t2 = get(v);
			fa[t1] = t2;
		}
		return 0;
	}
	
	void up(int now) {
		//rep(i, 1, 2 * n + 1) fa[i] = i;
		int p1 = 0, p2 = 0, u, v;
		for (auto i : tr[ls]) {
			u = edge[i].fi.fi; v = edge[i].fi.se;
			fa[u] = u; fa[u + n] = u + n;
			fa[v] = v; fa[v + n] = v + n;
		}
		for (auto i : tr[rs]) {
			u = edge[i].fi.fi; v = edge[i].fi.se;
			fa[u] = u; fa[u + n] = u + n;
			fa[v] = v; fa[v + n] = v + n;
		}	
		while (p1 < sz(tr[ls]) && p2 < sz(tr[rs])) {
			if (edge[tr[ls][p1]].se > edge[tr[rs][p2]].se) {
				if (solve(tr[ls][p1++], now)) return;
			}else if (solve(tr[rs][p2++], now)) return;
		}
		while (p1 < sz(tr[ls])) {
			if (solve(tr[ls][p1++], now)) return;
		}
		while (p2 < sz(tr[rs])) {
			if (solve(tr[rs][p2++], now)) return;
		}
	}
	
	void build(int l, int r,int now) {
		if (l == r) {
			tr[now].pb(l);
			return;
		}
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid + 1, r, rs);
		up(now);
	} 
	
	void qry(int L, int R, int l, int r, int now) {
	 	if (L <= l && R >= r) {
			vi c;
			int p1 =0, p2 = 0;
			while (p1 < sz(tr[now]) && p2 < sz(tmp)) {
				if (edge[tr[now][p1]].se > edge[tmp[p2]].se) {
					c.pb(tr[now][p1++]);
				}else c.pb(tmp[p2++]);
			}
			while (p1 < sz(tr[now])) c.pb(tr[now][p1++]);
			while (p2 < sz(tmp)) c.pb(tmp[p2++]);
			tmp = c;
			return; 
		}
		int mid = l + r >> 1;
		if (L <= mid) qry(L, R, l, mid, ls);
		if (R > mid) qry(L, R, mid + 1, r, rs); 
	 }
} seg;

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m >> q;
	rep(i, 1, m+1) {
		cin >> u >> v >> w;
		edge[i] = {{u, v}, w};
	}
	seg.build(1, m, 1);
	rep(cas, 0, q) {
		cin >> L >> R;
		tmp.clear();
		seg.qry(L, R, 1, m, 1);
		int ans = -1;
		rep(i, 1, 2 * n + 1) fa[i] = i;
		rep(i, 0, sz(tmp)) {
			u = edge[tmp[i]].fi.fi;v = edge[tmp[i]].fi.se;
			if (get(u) == get(v)) {
				ans = edge[tmp[i]].se;
				break;
			}else {
				fa[get(u)] = get(v + n);
				fa[get(u + n)] = get(v);
			}
		}
		cout << ans <<endl;
	}
	return 0;
}


