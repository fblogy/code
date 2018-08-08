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
 
const int N=1000005;
const int mod=1e9+7;
 
struct node{
    int x1,x2,y1,y2,w;
    node(int x1=0,int y1=0,int x2=0,int y2=0,int w=0):x1(x1),y1(y1),x2(x2),y2(y2),w(w){};
}op[N];
 
int n,m,T,aa,b,c,d,w,ans;
int s[N],a[N],f[N];
bool vis[N];

int id(int x,int y) {
	return (x-1)*m+y; 
} 
 
void add(int *s,node a) {
    s[id(a.x1,a.y1)]++;
    if (a.x2+1<=n) s[id(a.x2+1,a.y1)]--;
	if (a.y2+1<=m) s[id(a.x1,a.y2+1)]--;
	if (a.x2+1<=n&&a.y2+1<=m) s[id(a.x2+1,a.y2+1)]++; 
}
 
int main(){
  	freopen("a.in","r",stdin);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    scanf("%d%d%d",&n,&m,&T);
    rep(i,1,n+1) rep(j,1,m+1) scanf("%d",&a[id(i,j)]);
    rep(i,0,T) {
        scanf("%d%d%d%d%d",&aa,&b,&c,&d,&w);
        op[i]=node(aa,b,c,d,w);
    }
//    rep(i,0,n+2) f[i]=vi(m+2,0);
    rep(cas,0,T) add(f,op[cas]); 
    rep(i,1,n+1) rep(j,1,m+1) {
		if (i-1>=1) f[id(i,j)]+=f[id(i-1,j)];
		if (j-1>=1) f[id(i,j)]+=f[id(i,j-1)];
		if (i-1>=1&&j-1>=1) f[id(i,j)]-=f[id(i-1,j-1)];
	}//f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1]; 
    rep(k,0,20){
        fill_n(s+1,n*m,0);
        rep(cas,0,T) if (op[cas].w&(1<<k)) add(s,op[cas]);
        rep(i,1,n+1) rep(j,1,m+1) {
            if (i-1>=1) s[id(i,j)]+=s[id(i-1,j)];
			if (j-1>=1) s[id(i,j)]+=s[id(i,j-1)];
			if (i-1>=1&&j-1>=1) s[id(i,j)]-=s[id(i-1,j-1)];
            if (!vis[id(i,j)]){
				if ((1<<k)&(a[id(i,j)])) {
					if (f[id(i,j)]!=s[id(i,j)]) ans++,vis[id(i,j)]=1;
				}else {
					if (s[id(i,j)]>0) ans++,vis[id(i,j)]=1;
				}
			}
		}
    }
    printf("%d",ans);
    return 0;
}
