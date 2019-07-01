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
/*
	
*/
const ll INF = pw(62);
const int N = 100005;

int T, n, Q, D;
ll now;

struct node{
	int d[2], l, r, mi[2], ma[2];//sum, val, minp, p, id;
	bool operator <(const node &b)const{
		return d[Q] < b.d[Q];
	}
};

node a[N], ans, v, b[N];

struct KDTree{
	static const int N = 1e5 + 7;
	int root;
	node tr[N];

	inline void up(node &a, const node &b){
		rep(i, 0, D) {
			a.mi[i] = min(a.mi[i], b.mi[i]);
			a.ma[i] = max(a.ma[i], b.ma[i]);
		}
	}
	inline void insert(int now){
		int k = 0, p = root;
		if (!p) {root = now;return;}
		while (1) {
			up(tr[p], tr[now]);
    		if(tr[now].d[k] >= tr[p].d[k]){
        		if (!tr[p].r) {tr[p].r = now;return;}
				else p = tr[p].r;
    		}else{
        		if (!tr[p].l) {tr[p].l = now;return;}
        		else p = tr[p].l;
    		}
       		k = (k + 1) % D;
		}
	}

	int build(int l,int r,int k) {
		if (l > r) return 0;
		int mid = l+r>>1; Q = k;
		nth_element(a+l, a+mid, a+r+1);
		tr[mid] = a[mid];
		rep(i, 0, D) tr[mid].ma[i] = tr[mid].mi[i] = tr[mid].d[i];
		tr[mid].l = build(l, mid-1, k^1);
		tr[mid].r = build(mid+1, r, k^1);
		if (tr[mid].l) up(tr[mid], tr[tr[mid].l]);
		if (tr[mid].r) up(tr[mid], tr[tr[mid].r]);
		return mid;
	}

	inline ll sqr(ll x) {return x * x;}

	inline ll get(const node &v, int x) {
		if (!x) return INF+1;
		ll res = 0;
		rep(i, 0, D) {
			if (v.d[i] < tr[x].mi[i]) res += sqr(tr[x].mi[i] - v.d[i]);
			if (v.d[i] > tr[x].ma[i]) res += sqr(v.d[i] - tr[x].ma[i]);
 		}
		return res;
	}
 
	inline void check(const node &v, const node &p) {
		ll dis = 0;
		rep(i, 0, D) dis += sqr(p.d[i] - v.d[i]);
		if (dis) now = min(now, dis);
		return;
	}
 
	void ask(const node &v, int x) {
		if (!x) return;
		check(v, tr[x]);
		ll lm = get(v, tr[x].l), rm = get(v, tr[x].r);
		if (lm < rm) {
			if (lm <= now) ask(v, tr[x].l);
			if (rm <= now) ask(v, tr[x].r);
		}else {
			if (rm <= now) ask(v, tr[x].r);
			if (lm <= now) ask(v, tr[x].l);
		}
	}
} kdt;

int main(){
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	D = 2;
	cin >> T;
	rep(cas, 0, T) {
		cin >> n;
		rep(i, 1, n+1) 
			rep(j, 0, D) cin >> a[i].d[j];
		rep(i, 1, n+1) b[i] = a[i];
		kdt.root = kdt.build(1, n, 0);
		rep(i, 1, n+1) {
			now = INF;
			kdt.ask(b[i], kdt.root);
			cout << now << endl;
		}
	}
}

