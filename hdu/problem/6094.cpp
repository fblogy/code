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

int T, n, kk, s, t, x, m, u, v;

const ll inf = pw(30);

template<class U,class V>
struct MCMF{
    static const int N = 3e5 , M = 1e6;
    int h[N] , ing[N] , pre[N] , to[M] , ne[M] , e , s , t , n;
    U cap[M];V dis[N] , cost[M];
    void ini(int _n = N){ fill(h , h + (n=_n) , -1);e = 0;}
    void liu(int u,int v,U c,V w){ to[e] = v;ne[e] = h[u];cap[e] = c;cost[e] = w;h[u] = e++;}
    void link(int u,int v,U c,V w){ liu(u,v,c,w);liu(v,u,0,-w); }
    bool spfa(){
        queue<int> Q;
        fill(dis,dis+n,inf);
        ing[s] = true , dis[s] = 0;
        Q.push(s);
        while(!Q.empty()){
            int c = Q.front();Q.pop();ing[c] = false;
            for(int k=h[c];~k;k=ne[k]){
                int v = to[k];
                if(cap[k] <= 0) continue;
                if(dis[c] + cost[k] < dis[v]){
                    dis[v] = dis[c] + cost[k];
                    pre[v] = k;
                    if(!ing[v]) Q.push(v) , ing[v] = true;
                }
            }
        }
        return dis[t] != inf;
    }
    U flow;V mincost;
    pair<U,V> run(int _s,int _t){
        s = _s , t = _t;
        flow = mincost = 0;
        while(spfa()){
            U pl = pw(30);int p , k;
            for(p=t;p!=s;p=to[k^1]) pl = min(pl , cap[k=pre[p]]);
            for(p=t;p!=s;p=to[k^1]){
                k = pre[p];
                cap[k] -= pl;
                cap[k^1] += pl;
            }
            mincost += pl * dis[t];
            flow += pl;
            if (flow > kk) {
				mincost -= (flow - kk) * dis[t];
				flow = kk;
				break;
			}
			//de(mincost);
        }
        return make_pair(flow , mincost);
    }
};

template<class T>
struct Dinic{
    const static int N = 2e5 , M = N * 10;
    int s , t , n , h[N] , cur[N] , level[N] , q[N] , e , ne[M] , to[M];
    T cap[M] , flow;
    void liu(int u,int v,T w){ to[e] = v;ne[e] = h[u];cap[e] = w;h[u] = e++;}
    void link(int u,int v,T w){ liu(u , v , w);liu(v , u , 0);}
    void ini(int _n = N) { fill(h , h + (n=_n) , -1);e = 0;}
    bool bfs(){
        int L = 0 , R = 0;
        fill(level , level + n , -1);
        level[q[R++] = s] = 0;
        while(L < R && level[t] == -1){
            int c = q[L++];
            for(int k=h[c];~k;k=ne[k])
                if(cap[k] > 0 && level[to[k]] == -1)
                    level[q[R++] = to[k]] = level[c] + 1;
        }
        return ~level[t];
    }
    T dfs(int c,T mx){
        if(c == t) return mx;
        T ret = 0;
        for(int &k = cur[c];~k;k = ne[k]){
            if(level[to[k]] == level[c] + 1 && cap[k] > 0){
                T flow = dfs(to[k] , min(mx , cap[k]));
                ret += flow;cap[k] -= flow , cap[k^1] += flow;mx -= flow;
                if(!mx) return ret;
            }
        }
        level[c] = -1;
        return ret;
    }
    T run(int _s,int _t){
        s = _s , t = _t;
        flow = 0;
        while(bfs()){
            copy(h , h + n , cur);
            flow += dfs(s,~0U>>1);
        }
        return flow;
    }
};

template<class U,class V>
struct ZKW{
    static const int N = 2e5 , M = N * 10;
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
        if (flow > kk) return 0;
        if(Min == inf) return false;
        rep(i,0,n) if(v[i]) dis[i] += Min;
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

//Dinic<int> G;
//MCMF<int , ll> G;
ZKW<int, ll> G;

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> T;
	rep(cas, 0, T) {
		//cin >> n >> m >> kk;
		n = 4e4; m = 4; kk = 80000;
		G.ini(n * m + 10);
		s = n * m + 1; t = s + 1;
		rep(i, 1, n) {
			rep(j, 1, m+1) {
				//cin >> x;
				x = rand()%1000000;
				u = (i - 1) * m + j; v = i * m + j;
				if ((i + j) % 2 == 1) swap(u, v);
				G.link(u, v, 1, x);
			}
		}
		rep(i, 1, n+1) {
			rep(j, 1, m) {
				//cin >> x;
				x = rand()%1000000;
				u = (i - 1) * m + j; v = (i - 1) * m + j + 1;
				if ((i + j) % 2 == 1) swap(u, v);
				G.link(u, v, 1, x);
			}
		}
		rep(i, 1, n+1) rep(j, 1, m+1) {
			u = (i - 1) * m + j;
			if ((i + j) % 2 == 0) G.link(s, u, 1, 0);
			else G.link(u, t, 1, 0);
		}
		cout << G.run(s, t).fi << endl;
	} 
	return 0;
}


