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


const int N = 1e6 + 7;
vi tmp;
vector<pii> g[N];
int n, m, u, v, w, f[N], ans[N], p;
vector<pair<pii, int> > e[N];

int get(int x) {
	return x == f[x] ? x : f[x] = get(f[x]);
}
namespace BCC{
    const int N = 202020;
    vi key , bcc[N];
    int dfn[N] , low[N] , id[N] , st[N] , _st , _;
    void dfs(int c,int dep,vector<pii> g[]){
        int cc=0;st[_st++]=c;
        dfn[c]=low[c]=dep;
        for(auto e:g[c]){
            int t=e.fi;
            if(!dfn[t]){
                dfs(t,dep+1,g);
                low[c]=min(low[c],low[t]);
                if(low[t]>dfn[c]) key.pb(e.se);
            } else if(dfn[t] != dfn[c] - 1 || cc++)
                low[c] = min(low[c] , dfn[t]);
        }
        if(low[c]==dfn[c]){
            do{id[st[--_st]]=_;}while(st[_st]!=c);
            _++;
        }
    }
    int solve(vector<pii> g[]){
		//fill_n(dfn,n,_=0);
        //fill_n(low,n,_st=0);
        //fill_n(bcc,n,key=vi());
        _ = _st = 0;
        key = vi();
        for (auto i : tmp) dfn[i] = low[i] = 0;
        for (auto i : tmp) if(!dfn[i]) dfs(i,1,g);
       	//for (auto i : tmp) for(auto j:g[i]) if(id[i]!=id[j.fi]) ans[j.se] = 1;
		for (auto v : key) ans[v] = 1; 
		return _;
    }
};



int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 1, m+1) {
		cin >> u >> v >> w;
		e[w].pb(mp(mp(u, v), i));
	}
	rep(i, 1, n+1) f[i] = i;
	rep(i, 1, 1e6+1) if (sz(e[i]) > 0){
		for (auto t : e[i]) {
			u = t.fi.fi; v = t.fi.se; p = t.se;
			u = get(u);v = get(v);
			if (u == v) ans[p] = -1;else {
				tmp.pb(u);
				tmp.pb(v);
				g[u].pb(mp(v, p));
				g[v].pb(mp(u, p));	
			}
		}
		for (auto t : e[i]) {
			u = t.fi.fi; v = t.fi.se; p = t.se;
			f[get(u)] = get(v);
		}
		BCC :: solve(g);
		for (auto v : tmp) g[v].clear();
		tmp.clear();
	}
	rep(i, 1, m+1) {
		if (ans[i] == -1) cout << "none";
		else if (ans[i] == 0) cout << "at least one";
		else cout << "any";
		cout << endl;
	}
 	return 0;
}


