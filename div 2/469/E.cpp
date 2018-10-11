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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 1e5 + 7;
int n, m, h, t[N], v, u, p;
vi g[N];

namespace SCC {
    const int N = 100050;
    int dfn[N],low[N],id[N],st[N],_st,_,cc,du[N],siz[N];
    void dfs(int c,vi g[]){
        dfn[c]=low[c]=++cc;
        st[_st++]=c;
        for(auto t:g[c])
            if(!dfn[t])
                dfs(t,g),low[c]=min(low[c],low[t]);
            else if(!id[t])
                low[c]=min(low[c],dfn[t]);
        if(low[c]==dfn[c]){
            ++_;
            do{id[st[--_st]]=_;}while(st[_st]!=c);
        }
    }
    vi ng[N];
    int solve(int n,vi g[]){
        fill_n(dfn,n,cc=0);
        fill_n(low,n,_st=0);
        fill_n(id,n,_=0);
        rep(i,0,n) if(!dfn[i]) dfs(i,g);
        rep(i,0,n) --id[i], siz[id[i]]++;
        //fill_n(ng,_,vi());
        rep(i,0,n) for(auto j:g[i]) if(id[i]!=id[j]) {
			du[id[i]]++;
		}//ng[id[i]].pb(id[j]);
		int ma = 1 << 30, pos;
		rep(i, 0, _) if (du[i] == 0 && siz[i] < ma) {
			ma = siz[i];
			pos = i;
		}
		cout << siz[pos] << endl;
		rep(i, 0, n) if (id[i] == pos) {
			cout << i + 1 << " "; 
		}
        return pos;
    }
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m >> h;
	rep(i, 0, n) cin >> t[i];
	rep(i, 1, m+1) {
		cin >> u >> v;
		u--; v--;
		if ((t[u] + 1) % h == t[v]) g[u].pb(v);
		if ((t[v] + 1) % h == t[u]) g[v].pb(u);
	}	
	SCC :: solve(n, g);
	return 0;
}


