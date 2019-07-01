#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(a) cout << #a << " = " << a << " "
#define de(a) cout << #a << " = " << a << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;

const int N = 505;

int n, inf, L;
int g[N][N], G[N][N], pre[N], id[N], Pre[N];
char s[N], ch[N][N], cha[N];

int find(int x) {
	return (x == pre[x]) ? x : (pre[x] = find(pre[x]));
}
void join(int x, int y) {
	x = find(x), y = find(y);
	if(x < y) swap(x, y);
	pre[x] = y;
}

struct Trie{
	static const int N = ::N , M = 26;
	int ne[N][M] , fail[N] , fa[N] , rt , L;
	void ini(){ fill_n(ne[fail[0] = N-1],M,0);L = 0;rt = newnode();}
	int newnode(){ fill_n(ne[L],M,0); return L++; }
	void add(char *s){
		int p = rt;
		for(int i=0;s[i];++i){
			int c = s[i] - 'a';// modify
			if(!ne[p][c]) ne[p][c] = newnode() , fa[L-1] = p;
			int t = ne[p][c];
			g[p][t] = 1, ch[p][t] = s[i];
			p = ne[p][c];
		}
	}
	void Build(){
		vi v;v.pb(rt);
		rep(i,0,sz(v)){
			int c = v[i];
			rep(i,0,M) ne[c][i] ?
				v.pb(ne[c][i]) , fail[ne[c][i]] = ne[fail[c]][i] :
				ne[c][i] = ne[fail[c]][i];
		}
		rep(i, 0, L) if(fail[i]) g[i][fail[i]] = 0;
	}
}ac;

bitset<1005> fang;

// id starts from 0
// can handle multi edge, self ring
struct edge{int u,v,d,U,V;bitset<1005> b;};
struct DMST{
	static const int N = ::N , M = N * N , inf = 2e9;
	edge e[M];int n,m,vis[N],pre[N],id[N];int in[N];
	int index[N], Pre[N];
	void ini(int n) {this->n=n,m=0;}
	void addedge(int u,int v,int d) {e[m]=edge({u,v,d,u,v});e[m].b[m] = 1;m++;}
	int run(int root){
		int ans=0;
		while(1){
			rep(i,0,n) in[i]=inf;
			rep(i,0,m){
				int u=e[i].u , v=e[i].v;
				if(e[i].d < in[v] && u != v){
					in[v] = e[i].d , pre[v] = u;
					index[v] = i;
				}
			}
			rep(i,0,n) {
				if(i == root) continue; 
				if(in[i] == inf) return -1;
				fang ^= e[index[i]].b;
			}
			int cnt = 0;in[root] = 0;
			memset(id,-1,sizeof(*id)*n);
			memset(vis,-1,sizeof(*vis)*n);
			rep(i,0,n){
				ans+=in[i];int v=i;
				int t = index[i];
				while(vis[v] != i && id[v] == -1 && v!=root){
					vis[v] = i;v = pre[v];
				}
				if(v != root && id[v] == -1) {
					for(int u=pre[v];u != v;u = pre[u]) id[u] = cnt;
					id[v] = cnt++;
				}
			}
			if(cnt == 0) break;
			rep(i,0,n) if(id[i] == -1) id[i] = cnt++;
			rep(i,0,m) {
				int v=e[i].v;
				e[i].u = id[e[i].u]; e[i].v = id[e[i].v];
				if(e[i].u != e[i].v) {e[i].d -= in[v];e[i].b ^= e[index[v]].b;}
			}
			n=cnt;root=id[root];
		}
		return ans;
	}
}dmst;

int main() {
	freopen("dictionary.in", "r", stdin);
	freopen("dictionary.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	memset(g, 0x3f, sizeof(g));
	inf = g[0][0];
	cin >> n;
	ac.ini();
	rep(i, 0, n) {
		cin >> s;
		ac.add(s);
	}
	ac.Build();
	dmst.ini(ac.L);
	rep(i, 0, ac.L) rep(j, 0, ac.L) if(g[i][j] <= 1) {
		//dd(i);dd(j);de(g[i][j]);
		dmst.addedge(i, j, g[i][j]);
	}
	dmst.run(0);
	
	//de(dmst.m);
	memset(G, 0x3f, sizeof(G));
	rep(i, 0, ac.L) pre[i] = i;
	rep(i, 0, dmst.m) if (fang[i]) dmst.Pre[dmst.e[i].V] = dmst.e[i].U;
	rep(i, 1, ac.L) {
		int u = dmst.Pre[i], v = i;
		G[u][v] = g[u][v];
		if(G[u][v] == 0) join(u, v);
	}
	rep(i, 0, ac.L) if(i == find(i)) id[i] = ++L;
	rep(i, 1, ac.L) {
		int u = dmst.Pre[i], v = i;
		if(g[u][v] == 1) {
			Pre[id[find(v)]] = id[find(u)];
			cha[id[find(v)]] = ch[u][v];
		}
	}
	cout << L << endl << 0 << endl;
	rep(i, 2, L + 1) cout << Pre[i] << " " << cha[i] << endl;
	return 0;
}
/*
2
abcd
cdab
*/
