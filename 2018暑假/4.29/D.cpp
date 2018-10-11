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

const int N=2e6+5;
const int mod=1e9+7;

struct Edge
{
	int u,v,w,flag,next;
}edge[N];

struct Node
{
	int u,dis;
	bool operator<(Node n2)const
	{
		return dis > n2.dis;
	}
	Node(int u=0,int dis=0):u(u),dis(dis){}
};
int done[N];


int first[N], tot,n,m;
void addedge(int u,int v,int w)
{
	edge[tot].next = first[u];
	first[u] = tot;
	edge[tot].u = u;
	edge[tot].v = v;
	edge[tot].w = w;
	tot++;
}

bool ok = 0;
int pre[N],inq[N],dis[N];
int vis[N],ans[N];
void dfs(int u,int len)
{
	ans[len] = u;
	if(u==1){
		ok = 1;
		printf("%d",len);
		rep(i,1,len+1) printf(" %d",ans[i]);
		return ;
	}
	for(int i=first[u];i!=-1;i=edge[i].next){
		if(ok) return;
		if(edge[i].flag) continue;
		int v = edge[i].v;
		if(vis[v]) continue;
		vis[v] = 1;
		dfs(v,len+1);
	}
}

int main(){
	//freopen("a.in","r",stdin);
	memset(first,-1,sizeof(first));
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	
	memset(dis,0x3f3f,sizeof(dis));
	dis[1] = 0;
	priority_queue<Node> pq;
	pq.push(Node(1,0));
	while(!pq.empty())
	{
		Node ft = pq.top();
		pq.pop();
		int u = ft.u;
		if(done[u]) continue;
		done[u] = 1;
		for(int i=first[u];i!=-1;i=edge[i].next){
			int v = edge[i].v, w = edge[i].w;
			if(dis[v] <= dis[u]+w) continue;
			dis[v] = dis[u] + w;
			pre[v] = i;
			pq.push(Node(v,dis[v]));
		}
	}
	
	/*
	int p = 0;
	while(p!=1)
	{
		int i = pre[p];
		edge[i].flag = 1;
		edge[i^1].flag = 1;
		p = edge[i].u;
	}
	
	rep(i,2,n){
		p = i;
		while(p!=1)
		{
			int e = pre[p];
			edge[e].flag = 1;
			edge[e^1].flag = 1;
			p = edge[e].u;
		}
	}*/
	for(int i=0;i<tot;i++){
		int u = edge[i].u , v = edge[i].v, w = edge[i].w;
		if(dis[u]+w==dis[v]) edge[i^1].flag = 1;
	}
	vis[0] = 1;
	dfs(0,1);
	if(!ok) puts("impossible");
	return 0;
}
