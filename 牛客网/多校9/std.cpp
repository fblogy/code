#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100500+5;
inline long long read()
{
    long long x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct node
{
    int x,y,z;
}p[maxn];
int n;
map<int,int> H;
vector<int> Q;
void Li()
{
    for(int i=1;i<=n;i++)
        Q.push_back(p[i].z);
    sort(Q.begin(),Q.end());
    for(int i=1;i<=n;i++)
        p[i].z=lower_bound(Q.begin(),Q.end(),p[i].z)-Q.begin()+1;
}
bool cmpx(node A,node B)
{
    return A.x<B.x;
}
bool cmpy(node A,node B)
{
    return A.y<B.y;
}
int dp[maxn];
int d[maxn];
int lowbit(int x)
{
    return x&(-x);
}
void updata(int x,int val)
{
    for(int i=x;i<n+2;i+=lowbit(i))
        d[i]=max(d[i],val);
}
int query(int x)
{
    int res = 0;
    for(int i=x;i;i-=lowbit(i))
        res=max(res,d[i]);
    return res;
}
void init(int x)
{
    for(int i=x;i<n+2;i+=lowbit(i))
        d[i]=0;
}
void solve(int L,int R){
    int m=(L+R)>>1;
    sort(p+L,p+m+1,cmpy);
    sort(p+m+1,p+R+1,cmpy);
    int j=L;
    for(int i=m+1;i<=R;i++){
        for(;j<=m&&p[j].y<p[i].y;j++)
            updata(p[j].z,dp[p[j].x]);
        int tmp=query(p[i].z-1)+1;
        dp[p[i].x]=max(dp[p[i].x],tmp);
    }
    for(int i=L;i<=m;i++)init(p[i].z);
    sort(p+m+1,p+R+1,cmpx);
}

void CDQ(int L,int R){
    if(L==R)return;
    int m=(L+R)>>1;
    CDQ(L,m);
    solve(L,R);
    CDQ(m+1,R);
}
int main()
{
	freopen("a.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        p[i].y=read(),p[i].z=read();
        p[i].x = i;
        dp[i]=1;
    }
    //Li();
    CDQ(1,n);
    int Ans = 0;
    for(int i=1;i<=n;i++) cout << p[i].x << endl;
        //Ans=max(Ans,dp[i]);
    printf("%d\n",Ans);
}
