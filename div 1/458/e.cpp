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
vi g[N], tmp, tmp1;
ll ans[N], sum[N];
int h[1<<20];
int n, u, v;
string s;

namespace Centriod {
    const int N = :: N;
    int vis[N],sz[N];
    // 每棵树都要先初始化!! 表示该点是否被选为重心
    void ini() {
		memset(vis,0,sizeof(vis));
	}
    void dfssz(int c,int fa,int Sz,int &rt){
        sz[c] = 1;
        for(auto t : g[c]) if(!vis[t]&&t!=fa) dfssz(t,c,Sz,rt) , sz[c]+=sz[t];
        if(!rt && sz[c]*2>Sz) rt=c;
    }
    
    void get_h(int c, int fa, int w) {
    	w ^= pw(s[c] - 'a');
    	if (fa != 0) {tmp.pb(w);h[w] ++;}
    	if (w == 0 || (w & - w) == w) sum[c]++;
		for (auto t : g[c]) if (!vis[t] && t != fa) get_h(t, c, w), sum[c] += sum[t], sum[t] = 0;
		ans[c] += sum[c];
	}
    
    void del(int c, int fa, int w) {
		w ^= pw(s[c] - 'a');
		tmp1.pb(w);h[w] --;
		for (auto t : g[c]) if (!vis[t] && t != fa) del(t, c, w);
	}
	
    void cal(int c, int fa, int w) {
		w ^= pw(s[c] - 'a');
		rep(i, 0, 20) sum[c] += h[pw(i) ^ w];
		sum[c] += h[w];
		for (auto t : g[c]) if (!vis[t] && t != fa) cal(t, c, w), sum[c] += sum[t], sum[t] = 0;
		ans[c] += sum[c];
	}
	
    void solve(int c, int w) {
		del(c, 0, w);
		cal(c, 0, 0);
		rep(i, 0, sz(tmp1)) h[tmp1[i]]++;
		tmp1.clear();
	}
    
    void dfs(int c){
        int rt = 0;dfssz(c,0,0,rt);dfssz(c,0,sz[c],rt=0);
        // cal something
        vis[rt] = 1;
		get_h(rt, 0, 0);
		sum[rt] = 0;
		ll z = 0;
		for (auto t : g[rt]) if(!vis[t]) solve(t, pw(s[rt] - 'a')), z += sum[t], sum[t] = 0;
		ans[rt] += z / 2;
		rep(i, 0, sz(tmp)) h[tmp[i]]--;
		tmp.clear();
        for (auto t : g[rt]) if(!vis[t]) dfs(t);
    }
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n) {
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	cin >> s; s = " " + s;
	Centriod :: dfs(1);
	rep(i, 1, n+1) cout << ans[i] << " ";
	return 0;
}


