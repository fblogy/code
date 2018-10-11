#include <bits/stdc++.h>
//#include <ext/pb_ds/priority_queue.hpp>
#define rep(i,n) for(int i=1;i<=n;++i)
#define inf 0x3f3f3f3f
#define M 100005
#define N 3005
using namespace std;
//__gnu_pbds::priority_queue<int> q;

struct Eedge
{
    int x,y,w;
} e[M];
struct edge
{
    int v,c,f;
} ee[2][M];
struct node
{
    int len,pos;
};
int operator <(const node &a,const node &b)
{
    return a.len<b.len;
}
int cmp(Eedge x,Eedge y)
{
    if(x.x==y.x)return x.y<y.y;
    return x.x<y.x;
}
int b[2][N],d[N];
priority_queue<node> q;
int n,m,ans,x,y,z,tot[2],top,tp,ts,tr;
bool f[N],r;
int tab[N];
void adds(bool p,int x,int y,int w)
{
    ee[p][++tot[p]]=(edge)
    {
        y,w,b[p][x]
    };
    b[p][x]=tot[p];
}
void add(bool p,int x,int y,int w)
{
    adds(p,x,y,w);
    adds(p,y,x,w);
}
int main()
{
    while(scanf("%d%d",&n,&m))
    {
        memset(b,0,sizeof b);
        tot[0]=tot[1]=0;
        ans=inf;
        rep(i,m)
        {
            scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
            if(e[i].x>e[i].y)swap(e[i].x,e[i].y);
        }
        sort(e+1,e+m+1,cmp);
        top=0;
        rep(i,m)if(e[top].x!=e[i].x||e[top].y!=e[i].y)e[++top]=e[i];
        else e[top].w+=e[i].w;
        m=top;
        rep(i,m)if(e[i].x!=e[i].y)add(0,e[i].x,e[i].y,e[i].w);
        r=0;
        rep(zz,n-1)
        {
            memset(d,0,sizeof d);
            memset(f,0,sizeof f);
            d[1]=inf;
            q.push((node)
            {
                d[1],1
            });
            tp=0;
            while(!q.empty())
            {
                x=q.top().pos;
                q.pop();
                if(f[x])continue;
                for(int i=b[r][x]; i; i=ee[r][i].f)
                {
                    int v=ee[r][i].v;
                    if(!f[v])d[v]+=ee[r][i].c,q.push((node){d[v],v});
                }
                f[x]=1;
                ++tp;
                if(tp==n-zz+1)ts=x;
                if(tp==n-zz)tr=x;
            }
            tp=0;
            for(int i=b[r][ts]; i; i=ee[r][i].f)tp+=ee[r][i].c;
            r^=1;
            ans=min(ans,tp);
            memset(b[r],0,sizeof b[r]);
            tot[r]=0;
            rep(i,n)if(i!=tr&&i!=ts)
            {
                for(int j=b[r^1][i]; j; j=ee[r^1][j].f)
                    if(ee[r^1][j].v!=tr&&ee[r^1][j].v!=ts)adds(r,i,ee[r^1][j].v,ee[r^1][j].c);
            }
            top=0;
            memset(tab,0,sizeof tab);
            for(int i=b[r^1][ts]; i; i=ee[r^1][i].f)if(ee[r^1][i].v!=tr)tab[ee[r^1][i].v]+=ee[r^1][i].c;
            for(int i=b[r^1][tr]; i; i=ee[r^1][i].f)if(ee[r^1][i].v!=ts)tab[ee[r^1][i].v]+=ee[r^1][i].c;
            rep(i,n)if(tab[i])add(r,ts,i,tab[i]);
        }
        printf("%d\n",ans);
    }
}

