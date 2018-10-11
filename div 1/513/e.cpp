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
vi g[N];
int n, u, v;
ll cnt1, cnt0, sum, CNT0, CNT1, SUM, ans;

namespace Centriod {
    const int N = 201010;
    int vis[N],sz[N];
    void ini() {
		memset(vis,0,sizeof(vis));
	}
    void dfssz(int c,int fa,int Sz,int &rt){
        sz[c] = 1;
        for(auto t : g[c]) if(!vis[t]&&t!=fa) dfssz(t,c,Sz,rt) , sz[c]+=sz[t];
        if(!rt && sz[c]*2>Sz) rt=c;
    }
    void dfs2(int c, int fa, int d) {
		if (d & 1) cnt1++;else cnt0++;
		sum += d;
		for (auto t : g[c]) if (t != fa && !vis[t]) {
			dfs2(t, c, d+1);
		}
	}
    
    void dfs(int c){
        int rt=0;dfssz(c,0,0,rt);dfssz(c,0,sz[c],rt=0);
        CNT0 = 1; CNT1 = 0; SUM = 0;
        for (auto t : g[rt]) if (!vis[t]) {
			sum = 0; cnt0 = cnt1 = 0;
			dfs2(t, rt, 1);
			ans += SUM * (cnt0 + cnt1) + sum * (CNT0 + CNT1) + CNT0 * cnt1 + CNT1 * cnt0;
			SUM += sum;
			CNT0 += cnt0;
			CNT1 += cnt1;
		}
        vis[rt] = true;
        for(auto t : g[rt]) if(!vis[t]) dfs(t);
    }
}


int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	Centriod :: ini();
	Centriod :: dfs(1);
	cout << ans / 2;
	return 0;
}


