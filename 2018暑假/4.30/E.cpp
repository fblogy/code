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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
//---

const int N=100005;
const int mod=1e9+7;

int ans,x,y,xx,yy,f[N],n,m,num,root,p;

struct node{
	int x,y,w;
}a[N];

bool cmp(node a,node b) {
	return a.w<b.w;
}

int dfn[N],low[N],id[N],st[N],_st,_,fa[N];
vector<pii> g[N];

void dfs(int c,int dep,vector<pii> g[]){
	int cc=0;st[_st++]=c;
	dfn[c]=low[c]=dep;fa[c]=root;
	rep(i,0,sz(g[c])) if (g[c][i].se<a[p].w){
		int t=g[c][i].fi;
		if (!dfn[t]) {
			dfs(t,dep+1,g);
			low[c]=min(low[c],low[t]);
		}else if (dfn[t]!=dfn[c]-1 ||cc++)
			low[c]=min(low[c],dfn[t]);
	}
	if (low[c]==dfn[c]) {
		do{id[st[--_st]]=_;} while (st[_st]!=c);
		_++;
	}
}

int solve(int n,vector<pii> g[]) {
	fill_n(dfn,n,_=0);
	fill_n(low,n,_st=0);
	rep(i,0,n) if (!dfn[i]) {root=i;dfs(i,1,g);}
	x=a[p].x;y=a[p].y;
	if (id[x]==id[y]) {
		int num1=0,num2=0;
		rep(i,0,sz(g[x])) if (g[x][i].se<a[p].w&&id[g[x][i].fi]==id[x]) num1++;
		rep(i,0,sz(g[y])) if (g[y][i].se<a[p].w&&id[g[y][i].fi]==id[y]) num2++;
		return min(num1,num2);
	}else {
		if (fa[x]==fa[y]) return 1;else  return 0;
	}
}

int main(){
	freopen("a.in","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,m+1) {
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
		g[--a[i].x].pb(mp(--a[i].y,a[i].w));
		g[a[i].y].pb(mp(a[i].x,a[i].w));
	}
	sort(a+1,a+m+1,cmp); 
	rep(i,1,m+1) {
		p=i;
		ans+=solve(n,g);
	}
	printf("%d",ans);
	return 0;
}
