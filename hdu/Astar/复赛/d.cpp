#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define endl "\n"
#define ite iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;
//---

const int N = 100005;
const int mod = 1e9+7;

int ma, x, y, o, tr[N * 4], ans;
vector<int> pos[N][3];
int l1, r1, n, R, nn, p;

struct node {
	int i, x, y, z, ma, type, pos;
} a[N], tmp[N];

int Add(int x, int y) {
	return (x + y) % mod;
}

template<class T>
struct Fenwick{
    static const int N =2e5+7;
    int n;T a1[N];
    void ini(int _n){ 
		fill_n(a1+1,n=_n,0);
	}
	void add(T *a,int p,T d) { for(; p<=n; p+=p & -p) a[p] = Add(a[p], d); }
	void del(T *a,int p) { for(; p<=n; p+=p & -p) a[p] = 0; }
	T qry(T *a,int p) { T r=0; for(; p>=1; p-=p & -p) r = Add(r, a[p]); return r; }
};


Fenwick<int> fen;

bool cmpi(const node &a,const node &b) {
	if (a.i != b.i) return a.i < b.i;
	if (a.x != b.x) return a.x > b.x;
	if (a.y != b.y) return a.y > b.y;
	return a.z > b.z;
}

bool cmpx(const node &a,const node &b) {
	if (a.x != b.x) return a.x < b.x;
	if (a.y != b.y) return a.y > b.y;
	return a.z > b.z;
}

bool cmpy(const node &a,const node &b) {
	return a.y < b.y;
}

void solve(node *a, int l, int r) {
	int mid = l + r >> 1;
	sort(a + l, a + mid + 1, cmpy);
	sort(a + mid + 1, a + r + 1, cmpy);
	p = l;
	rep(i, mid + 1, r + 1){
		while (p <= mid && a[p].y < a[i].y) {
			if (!a[p].type) fen.add(fen.a1, a[p].z, a[p].ma);
			p++;
		}
		if (a[i].type) {
			ma = fen.qry(fen.a1, a[i].z - 1);
			a[i].ma = Add(a[i].ma, ma);
		}
	}
	rep(i, l, p) fen.del(fen.a1, a[i].z);
	sort(a + mid +1, a + r + 1, cmpx);
}

void CDQ2(int l, int r) {
	if (l == r) return;
	int mid = (l + r) >> 1;
	CDQ2(l, mid);
	solve(tmp, l, r);
	CDQ2(mid+1, r); 
}

void CDQ(int l, int r){
	if (l == r) return;
	int mid = (l + r) >> 1;
	CDQ(l, mid);
	rep(i, l, r+1) tmp[i] = a[i], tmp[i].type = (i > mid), tmp[i].pos = i;
	sort(tmp + l, tmp + r + 1, cmpx);
	CDQ2(l, r);
	rep(i, l, r+1) if (tmp[i].type) a[tmp[i].pos] = tmp[i];
	CDQ(mid+1, r);
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n+1) cin >> x, pos[x][0].pb(i);
	rep(i, 1, n+1) cin >> x, pos[x][1].pb(i);
	rep(i, 1, n+1) cin >> x, pos[x][2].pb(i);
	//rep(i, 1, n+1) rep(j, 0, 3) reverse(all(pos[i][j]));
	rep(i, 1, n+1) {
		cin >> x;
		rep(j, 0, sz(pos[x][0])) { 
			rep(k, 0, sz(pos[x][1]))
				rep(l, 0, sz(pos[x][2])) {
					a[++nn] = {i, pos[x][0][j], pos[x][1][k], pos[x][2][l], 1, 0, 0};
				}
		} 
	}
	fen.ini(n);
	n = nn;
	sort(a + 1, a + n + 1, cmpi);
	CDQ(1, n);
	rep(i, 1, n+1) ans = Add(ans, a[i].ma);
	cout << ans;
	return 0;
}

