// BCC¶¨Ïò×ªSCC 
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

const int N = 4e5 + 7;
int a[N], b[N], n, m, u, v;
vector<pii> g[N];
namespace BCC{
    const int N = 402020;
    vi key;
    vector<pii> ans,  bcc[N];
    int dfn[N] , low[N] , id[N] , st[N] , _st , _, cnt[N], p, w;
    void dfs(int c,int dep,vector<pii> g[]){
        int cc=0;st[_st++]=c;
        dfn[c]=low[c]=dep;
        for(auto e:g[c]){
            int t=e.fi;
            if(!dfn[t]){
                dfs(t,dep+1,g);
                low[c]=min(low[c],low[t]);
                //if(low[t]>dfn[c]) key.pb(e.se);
            } else if(dfn[t] != dfn[c] - 1 || cc++)
                low[c] = min(low[c] , dfn[t]);
        }
        if(low[c]==dfn[c]){
            do{id[st[--_st]]=_;}while(st[_st]!=c);
            _++;
        }
    }
    
    void dfs2(int c,int dep,vector<pii> g[]){
        dfn[c]=dep;
        for(auto e:g[c]){
            int t=e.fi;
            if(!dfn[t]){
                ans.pb(mp(e.se, t));
				dfs2(t,dep+1,g);
            }
        }
    }
    
	void dfs3(int c,int fa,vector<pii> g[]){
		int cc = 0;
        dfn[c] = low[c] = ++w;
        for(auto e:g[c]){
            int t=e.fi;
            if (id[t] != id[c]) continue;
            if (t == fa) continue;
            if(!dfn[t]){  
            	if (a[e.se] != c) swap(a[e.se], b[e.se]);
				dfs3(t, c, g);
            } else if (low[c] > low[t]) {
				if (a[e.se] != c) swap(a[e.se], b[e.se]);
			} 
        }
    }
    
    int solve(int n,vector<pii> g[]){
        fill_n(dfn,n,_=0);
        fill_n(low,n,_st=0);
        fill_n(bcc,n,vector<pii>());
        rep(i,0,n) if(!dfn[i]) dfs(i,1,g);
        rep(i,0,n) for(auto j:g[i]) if(id[i]!=id[j.fi])
            bcc[id[i]].pb(mp(id[j.fi], j.se));
        rep(i, 0, n) cnt[id[i]]++;
        p = max_element(cnt, cnt + _) - cnt;
        fill_n(dfn,n,_=0);
        dfs2(p, 1, bcc);
        fill_n(dfn,n,_=0);
        rep(i, 0, n) if (!dfn[i]) dfs3(i, -1, g);
    	for (auto t : ans) {
			if (id[a[t.fi]] != t.se) swap(a[t.fi], b[t.fi]);
		}
		cout << cnt[p] << endl;
		rep(i, 1, m+1) cout << a[i]+1 << " " << b[i]+1 << endl;
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
		cin >> u >> v;
		u--; v--;
		a[i] = u; b[i] = v;
		g[u].pb(mp(v, i));
		g[v].pb(mp(u, i)); 
	}
	BCC::solve(n, g);
	return 0;
}


