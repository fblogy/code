
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000
struct node
{
    int s,v;
    bool operator <(const node &a)const
    {
        return a.v<v;
    }
};
int V[15],dis[100005],pre[100005],num[100005];
int p,v,u;
void print(int x)
{
    if(pre[x]==-1)
    {
        cout<<u;
        return ;
    }
    print(pre[x]);
    cout<<num[x];
}
int bfs(int x)
{
    memset(dis,INF,sizeof dis);
    dis[x]=0;
    pre[x]=-1;
    priority_queue<node>que;
    que.push({x,0});
    while(!que.empty())
    {
        node tem=que.top();
        que.pop();
        if((tem.s*10+v)%p==0)
        {
            print(tem.s);
            cout<<v<<endl;
            return 1;
        }
        for(int i=0;i<10;i++)
            if(V[i])
        {
            int ns=(tem.s*10+i)%p;
            if(dis[ns]>dis[tem.s]+V[i])
            {
                dis[ns]=dis[tem.s]+V[i];
                pre[ns]=tem.s;
                num[ns]=i;
                que.push({ns,dis[ns]});
            }
        }
    }
    return 0;
}
int main()
{
    int a,b,n;
    cin>>a>>b>>n;
    p=__gcd(a,b);
    int w[12];
    for(int i=0;i<n;i++)
    {
       cin>>w[i];
    }
    for(int i=0;i<n;i++)
        cin>>V[w[i]];
 
    cin>>u>>v;
    if(bfs(u%p)==0)cout<<-1<<endl;
}
