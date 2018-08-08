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

int n,a[N];
ll ans,tmp,now;

namespace Bell{
	const int N=1005,mod=::mod;
	int C[N][N],B[N];
	ll pow_mod(ll x,ll k){
		ll res=1;
		while (k>0) {
			if (k&1) res=res*x%mod;x=x*x%mod;k>>=1;
		}
		return res;
	}
	void init(){
		rep(i,0,N) {
			C[i][0]=C[i][i]=1;
			rep(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
		B[0]=1;
		rep(i,1,N) {
			B[i]=0;
			rep(j,0,i) 
				B[i]=(B[i]-1ll*C[i+1][j]*B[j]%mod+mod)%mod;
			B[i]=1ll*B[i]*pow_mod(C[i+1][i],mod-2)%mod;
		}
	} 
	int cal(int n,int k) {
		int ans=pow_mod(k+1,mod-2),sum=0;
		rep(i,0,k+1) 
			sum=(sum+1ll*C[k+1][i]*B[i]%mod*pow_mod(n,k+1-i)%mod)%mod;
		return 1ll*ans*sum%mod;
	}
} 

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	Bell::init();
	while (cin>>n) {
		rep(i,1,n+1) cin>>a[i];
		sort(a+1,a+n+1);
		now=1;ans=0;
		rep(i,1,n+1) {
			if (a[i-1]<a[i]) {
				tmp=Bell::pow_mod(a[i],n-i+2);
				tmp-=(a[i-1]+1)*Bell::pow_mod(a[i-1],n-i+1)%mod;
				tmp-=Bell::cal(a[i],n-i+1)-Bell::cal(a[i-1]+1,n-i+1);
				tmp%=mod;
				ans=(ans+tmp*now)%mod;
			}
			now=now*a[i]%mod; 
		}
		if (ans<0) ans+=mod;
		cout<<ans<<endl;
	}
	return 0;
}

