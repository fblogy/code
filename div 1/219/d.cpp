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

const int N = 1e5 + 7;
set<pii> s;
int sum, n, k, u, v, l, ans;
vi g[N];

struct LCARMQ{
    static const int N = 101010 << 1;
    int a[20][N] , lft[N] , dep[N] , lg[N] , L;
    int rmin(int x,int y){return dep[x] < dep[y] ? x : y;}
    void add(int x){ a[0][L++] = x;}
    void dfs(int c,int fa,const vi g[]){
        lft[c]=L;add(c);
        for(auto t : g[c]) if(t!=fa) dep[t]=dep[c]+1,dfs(t,c,g),add(c);
    }
    void Build(const vi g[]){
        L = 0;dfs(1,-1,g);
        rep(i,2,L) lg[i]=lg[i>>1]+1;
        rep(i,1,20){
            int lim = L+1-(1<<i);
            rep(j,0,lim) a[i][j] = rmin(a[i-1][j] , a[i-1][j+(1<<i>>1)]);
        }
    }
    int lca(int x,int y){
        x = lft[x] , y = lft[y];
        if(x > y) swap(x , y);
        int i = lg[y-x+1];
        return rmin(a[i][x] , a[i][y+1-(1<<i)]);
    }
} R;

int dis(int x, int y) {
	int lca = R.lca(x, y);
	return R.dep[x] + R.dep[y] - 2 * R.dep[lca];
}

void ADD(int x) {
	s.insert(mp(R.lft[x], x));
	auto tmp = s.find(mp(R.lft[x], x));
	int u = (*(--tmp)).se;
	++tmp;
	int v = (*(++tmp)).se;
	if (u == -1) u = (*(--(--s.end()))).se;
	if (v == R.L) v = (*(++s.begin())).se;
	sum += (dis(x, u) + dis(x, v) - dis(u, v)) / 2; 
}

void DEL(int x) {
	auto tmp = s.find(mp(R.lft[x], x));
	int u = (*(--tmp)).se;
	++tmp;
	int v = (*(++tmp)).se;
	if (u == -1) u = (*(--(--s.end()))).se;
	if (v == R.L) v = (*(++s.begin())).se;
	sum -= (dis(x, u) + dis(x, v) - dis(u, v)) / 2;
	s.erase(mp(R.lft[x], x));
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> k;
	rep(i, 1, n) {
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	R.Build(g);
	s.insert(mp(-1, -1));
	s.insert(mp(R.L, R.L));
	l = 1;sum = 1;s.insert(mp(R.lft[1], 1));ans = 1;
	rep(i, 2, n+1) {
		ADD(i);//de(sum);
		while (sum > k) DEL(l++);
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}


