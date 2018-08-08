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
const int Len=333;
const int B=(N-1)/Len+1;

ll jc[N],inv[N],now,T;
int n,m,pn,pm,b,ans[N];
vector<pair<pii,int> > g[B];

ll qpow(ll a,ll b) {
	ll res=1;
	while (b>0) {
		if (b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

ll c(int n,int m) {
	if (m<0||m>n)return 0;
	return jc[n]*inv[m]%mod*inv[n-m]%mod;
}

bool cmp(pair<pii,int> a,pair<pii,int> b) {return a.fi.se<b.fi.se;}


int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	jc[0]=1;rep(i,1,N) jc[i]=jc[i-1]*i%mod;
	inv[N-1]=qpow(jc[N-1],mod-2);
	for(int i=N-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	cin>>T;
	rep(i,0,T) {
		cin>>n>>m;
		b=n/Len;
		g[b].pb(mp(mp(n,m),i));
	}
	rep(i,0,B) {
		sort(g[i].begin(),g[i].end(),cmp);
		pn=i*Len;pm=0;now=c(pn,pm);
		rep(j,0,sz(g[i])) {
			int x=g[i][j].fi.fi,y=g[i][j].fi.se,pos=g[i][j].se;
			while(pn>x) {
				now+=c(pn-1,pm);now*=inv[2];now%=mod;
				pn--;
			}
			while(pn<x) {
				now*=2;now-=c(pn,pm);now%=mod;
				pn++;
			}
			while (pm<y) {
				pm++;
				now+=c(pn,pm);now%=mod;
			}
			if (now<0) now+=mod;
			ans[pos]=now;
		}	
	}
	rep(i,0,T) cout<<ans[i]<<endl;
	return 0;
}

