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

const int N=105;
const int mod=1e9+7;

int T,n,m,a[N],v[N],num,l[N],r[N],g[N][N];
ll f[2][N][N][N],ans;
vector<pair<pii,int> > fang;
bool o;


ll qpow(ll a,ll b){
	ll res=1;
	while (b>0) {
		if (b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

int gcd(int a,int b){
	if (b==0) return a;
	return gcd(b,a%b);
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	rep(i,1,N) rep(j,1,N) g[i][j]=gcd(i,j);  
	m=100;	
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j+=i) 
			for(int k=j;k<=m;k+=j) fang.pb(mp(mp(k,j),i));	
	rep(cas,0,T) {
		cin>>n>>m;
		rep(i,1,n+1) cin>>a[i];
		rep(i,1,m+1) cin>>v[i];
		num=0;
		rep(i,1,n+1) if (a[i]==0) l[i]=1,r[i]=m,num++;else l[i]=r[i]=a[i];
		rep(k,0,sz(fang)) {
			int a=fang[k].fi.fi,b=fang[k].fi.se,c=fang[k].se;
			f[0][a][b][c]=f[1][a][b][c]=0;
		}
		rep(i,l[1],r[1]+1)
			rep(j,l[2],r[2]+1)
				rep(k,l[3],r[3]+1)
					f[o][k][g[j][k]][g[g[j][k]][i]]++;
		rep(i,4,n+1) {
			o^=1;
			rep(j,l[i],r[i]+1) {
				rep(k,0,sz(fang)){
					int a=fang[k].fi.fi,b=fang[k].fi.se,c=fang[k].se;
					(f[o][j][g[a][j]][g[b][j]]+=f[o^1][a][b][c]*v[g[j][c]])%=mod;
				}
			}
			rep(k,0,sz(fang)) {
				int a=fang[k].fi.fi,b=fang[k].fi.se,c=fang[k].se;
				f[o^1][a][b][c]=0;
			}
		}
		ans=0;
		rep(k,0,sz(fang)) {
			int a=fang[k].fi.fi,b=fang[k].fi.se,c=fang[k].se;
			ans+=f[o][a][b][c];
			ans%=mod;
		}
		ans=ans*qpow(qpow(m,num),mod-2)%mod;
		cout<<ans<<endl;
	} 
	return 0;
}

