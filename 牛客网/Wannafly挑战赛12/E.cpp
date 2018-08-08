#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(x) (int)x.size()
#define de(x) cout<< #x<<" = "<<x<<endl
#define dd(x) cout<< #x<<" = "<<x<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//------
 
const int N=100005;
const int mod=1e9+7;
int n,b,a,u,v,c[100],va[100],an[N*400],pos,fa[N*400],h[N*400],hh[N*400],l,r,g,x,y,num,num1,ann[N*400],w[N*400];
ll d[N],ans;
int gcd(int a,int b) {
    if (b==0) return a;
    return gcd(b,a%b);
}
 
bool check(int x){
    num=num1=0;string s1=""+u,s2=""+u;
    ann[++num1]=v;while (x) {ann[++num1]=hh[x];x=fa[x];}
    an[++num]=v;y=pos;while (y) {an[++num]=hh[y];y=fa[y];}
	for(int i=num1;i>=1;i--) s1+=ann[i];
	for(int i=num;i>=1;i--) s2+=an[i];
	return s1<s2;
}
 
int main() {
    scanf("%d%d%d",&a,&b,&n);
    rep(i,1,n+1) scanf("%d",&c[i]);
    memset(va,-1,sizeof(va));
    rep(i,1,n+1) {
        scanf("%d",&x);
        if (va[c[i]]==-1) va[c[i]]=x;
        else va[c[i]]=min(va[c[i]],x);
    }
    scanf("%d%d",&u,&v);
    g=gcd(a,b);
    memset(d,0x3f,sizeof(d));
    l=r=0;h[0]=u%g;hh[0]=u;d[u%g]=va[u];w[0]=va[u];
    ans=-1;
    while (l<=r) {
        x=h[l];num=num1=0;
        if ((x*10+v)%g==0){
            if (ans>w[l] || ans==-1) {
                ans=w[l];pos=l;
            }else if (ans==w[l] && check(l)){
                pos=l;
            }
        } 
        rep(i,0,10) if (va[i]>=0) {
            y=(x*10+i)%g;
            if (d[y]>=w[l]+va[i] && (ans>=w[l]+va[i]||ans==-1)) {
                d[y]=w[l]+va[i];
                h[++r]=y;hh[r]=i;fa[r]=l;w[r]=d[y];
            }
        }
        l++;
    }
    num=0;an[++num]=v;
    while (pos) {an[++num]=hh[pos];pos=fa[pos];}
    an[++num]=u;
    if(ans==-1) printf("-1");else
    for (int i=num;i>=1;i--) cout<<an[i];
    return 0;
}
