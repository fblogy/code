// codeforces 553E
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<complex>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
#define LL long long
#define inf 1ll<<30
#define Pi acos(-1.0)
#define upd(x,y) if ((x)>(y)) (x)=(y)
#define free(a) freopen(a".in","r",stdin),freopen(a".out","w",stdout);
using namespace std;
inline int gi() {
    int x=0,f=1;char ch=getchar();
    while (ch<'0' || ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0' && ch<='9') {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
 
//typedef complex<double> E;
const int maxn=110,maxm=210,maxt=20010;
//E A[maxt<<2],B[maxt<<2];
int rev[maxt<<2],dis[maxn][maxn],n,m,T,X,N,L;
double f[maxn][maxt<<1],P[maxm][maxt<<1],S[maxm][maxt<<1];
 
struct edge {int u,v,w;}e[maxm];
struct E{ double x,y; }A[maxt<<2],B[maxt<<2];
inline E operator + (const E &a,const E &b) { return (E){a.x+b.x,a.y+b.y}; }
inline E operator - (const E &a,const E &b) { return (E){a.x-b.x,a.y-b.y}; }
inline E operator * (const E &a,const E &b) { return (E){a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x}; }
 
void FFT(E *a,int f) {
    for (int i=0;i<N;i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
    for (int i=1;i<N;i<<=1) {
        E wn=(E){cos(Pi/i),f*sin(Pi/i)};
        for (int p=i<<1,j=0;j<N;j+=p) {
            E w=(E){1,0};
            for (int k=0;k<i;k++,w=w*wn) {
                E x=a[j+k],y=a[j+k+i]*w;
                a[j+k]=x+y;a[j+k+i]=x-y;
            }
        }
    }
}
long long cnt;
void calculate(int l,int r,int mid) {
    int len=r-l;
    
    L=-1;for (N=1;N<=len-1+r-mid;N<<=1) L++;
    for (int i=0;i<N;i++) rev[i]=(rev[i>>1]>>1) | ((i&1)<<L);
    
    for (int j=1;j<=m;j++) {
           //mdzz?????
        
        for (int i=0;i<N;i++) A[i]=B[i]=(E){0,0};
        for (int i=0;i<r-mid+1;i++) A[i]=(E){f[e[j].v][r-i],0};
        for (int i=0;i<len;i++) B[i]=(E){P[j][i+1],0};
        FFT(A,1);FFT(B,1);
        for (int i=0;i<N;i++) A[i]=A[i]*B[i];
        FFT(A,-1);
        for (int i=mid-1;i>=l;i--) S[j][i]+=A[r-i-1].x/N;
    }
}
void solve(int l,int r) {
    if (l==r) {
        for (int i=1;i<=m;i++) f[e[i].u][l]=min(f[e[i].u][l],S[i][l]+e[i].w);
        return;
    }
    int mid=(l+r)>>1;
    solve(mid+1,r);
    calculate(l,r,mid+1);
    solve(l,mid);
}
 
int main() {
	freopen("a.in","r",stdin);
    n=gi(),m=gi(),T=gi(),X=gi();
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) dis[i][j]=inf;
        dis[i][i]=0;
    }
    for (int i=1;i<=m;i++) {
        e[i].u=gi(),e[i].v=gi(),e[i].w=gi();
        dis[e[i].u][e[i].v]=min(dis[e[i].u][e[i].v],e[i].w);
        for (int x,j=1;j<=T;j++) {
            x=gi();
            P[i][j]=(double)x/100000;
        }
    }
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (i!=j && j!=k && i!=k && dis[i][k]!=inf && dis[k][j]!=inf)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for (int i=0;i<=T;i++) f[n][i]=0;
    for (int i=T+1;i<=2*T;i++) f[n][i]=X;
    for (int i=1;i<n;i++)
        for (int j=0;j<=2*T;j++) {
            if (j>T) f[i][j]=dis[i][n]+X;
            else f[i][j]=inf;
        }
    calculate(1,T*2,T+1);
    solve(0,T);
    cout << cnt << endl;
    printf("%.6lf\n",f[1][0]);
    return 0;
}
 
