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

const ll inf = pw(60);
const int N = 1010;
int a[N], b[N], n, m, k, me, ms, w1, w2, u, v, t, s;
ll ans;
template<class U,class V>
struct ZKW{
    static const int N = 2020 , M = 40404;
    int h[N] , ing[N] , v[N] , to[M] , ne[M] , e , s , t , n;
    U cap[M];V dis[N] , cost[M];
    void ini(int _n = N){ fill(h , h + (n=_n) , -1);e = 0;}
    void liu(int u,int v,U c,V w){ to[e] = v;ne[e] = h[u];cap[e] = c;cost[e] = w;h[u] = e++;}
    void link(int u,int v,U c,V w){ liu(u,v,c,w);liu(v,u,0,-w); }
    void spfa(){
        queue<int> Q;
        fill(dis,dis+n,inf);
        ing[t] = true , dis[t] = 0;
        Q.push(t);
        while(!Q.empty()){
            int c = Q.front();Q.pop();ing[c] = false;
            for(int k=h[c];~k;k=ne[k]){
                int v = to[k];
                if(cap[k^1] <= 0) continue;
                if(dis[c] + cost[k^1] < dis[v]){
                    dis[v] = dis[c] + cost[k^1];
                    if(!ing[v]) Q.push(v) , ing[v] = true;
                }
            }
        }
    }
    U flow;V mincost;
    bool modlable(){
        V Min = inf;
        rep(c,0,n) if(v[c])
            for(int k=h[c];~k;k=ne[k]){
                int t=to[k];
                if(!v[t] && cap[k] > 0)
                    Min = min(Min , dis[t] + cost[k] - dis[c]);
            }
        if(Min == inf) return false;
        rep(i,0,n) if(v[i]) dis[i] += Min;
		//if (dis[s] > 0) return 0;
        return true;
    }
    U dfs(int c,U mx){
        if(c == t) return flow += mx , mincost += mx * dis[s] , mx;
        v[c] = true;U ret = 0;
        for(int k=h[c];~k;k=ne[k]){
            int t = to[k];
            if(!v[t] && cap[k] > 0 && dis[c] - cost[k] == dis[t]){
                U tmp = dfs(t , min(cap[k] , mx - ret));
                cap[k] -= tmp , cap[k^1] += tmp;
                ret += tmp;
                if(ret == mx) return ret;
            }
        }
        return ret;
    }
    pair<U,V> run(int _s,int _t){
        s = _s , t = _t;
        spfa();
        flow = mincost = 0;
        do do memset(v,0,sizeof(v[0])*n);
            while(dfs(s,inf));
        while(modlable());
        return make_pair(flow , mincost);
    }
};

ZKW<ll, ll> G;

int main() {
	freopen("delight.in","r",stdin);
    freopen("delight.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> k >> ms >> me;
	rep(i, 1, n+1) cin >> a[i], ans += a[i];
	rep(i, 1, n+1) cin >> b[i];
	m = n - k + 1; w1 = me; w2 = k - ms;
	s = 2 * m + 2; t = 2 * m + 3;
	G.ini(2 * m + 10);
	rep(i, 1, n+1) {
		if (i <= k) u = 1;else u = (i - k) * 2 + 1;
		if (i <= m - 1) v = i * 2 + 1;else v = 2 * m + 1;
		G.link(u, v, 1, a[i] - b[i]);
	}
	rep(i, 1, m+1) {
		G.link(i * 2, i * 2 - 1, inf, 0);
		G.link(i * 2, i * 2 + 1, inf, 0);
	}
	G.link(s, 1, w1, 0);
	rep(i, 1, m+1) {
		G.link(s, i * 2, w2 - w1, 0);
		if (i != m) G.link(i * 2 + 1, t, w2 - w1, 0);
	}
	G.link(m * 2 + 1, t, w2, 0);
	cout << -G.run(s, t).se  + ans << endl;
	rep(i, 0, n) if(G.cap[i * 2] == 1) cout << 'S';else cout << 'E';
	return 0;
}


