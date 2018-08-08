#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
//---

const int N=100005;
const int mod=1e9+7;

int T,n,fa[N],u,v;
ll ans,w;
vi g[N];
bool vis[N];

struct node{
	ll a,b;
	int i,now;
	bool operator <(const node c) const{
		if (a<b && c.a>=c.b) return 0;
		if (a>=b && c.a<c.b) return 1;
		if (a<b && c.a<c.b) return a>c.a;
		if (a>=b && c.a>=c.b) return b<c.b;
	}
} a[N];

priority_queue<node> q;


int get(int x) {
	if (!vis[fa[x]]) return fa[x];
	return fa[x]=get(fa[x]);
}

void dfs(int u) {
	rep(i,0,sz(g[u])) {
		int v=g[u][i];
		if (fa[v]==0) {
			fa[v]=u;
			dfs(v);
		}
	}
}
	
int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	rep(cas,0,T) {
		cin>>n;
		rep(i,2,n+1) cin>>a[i].a>>a[i].b,a[i].i=i,a[i].now=0,q.push(a[i]);
		rep(i,1,n) {
			cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		fill_n(vis,n+1,0);
		fill_n(fa,n+1,0);
		fa[1]=1;dfs(1);
		ans=w=0;
		while (!q.empty()) {
			node tmp=q.top();q.pop();
			int Fa=get(tmp.i);
			if (Fa==1) {
				vis[tmp.i]=1;
				w-=tmp.a;
				ans=min(ans,w);
				w+=tmp.b;			
			}else {
				vis[tmp.i]=1;
				if (tmp.a<a[Fa].b){
					a[Fa].b+=tmp.b-tmp.a;
				}else {
					a[Fa].a+=tmp.a-a[Fa].b;
					a[Fa].b=tmp.b;
				}
				a[Fa].now++;
				q.push(a[Fa]);
			}
			while (!q.empty()&&q.top().now!=a[q.top().i].now) q.pop();	
		}
		cout<<-ans<<endl;
		rep(i,1,n+1) g[i].clear();
	}
	return 0;
}

