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
int n,mod,q,l,r;
ll a[N];
map<ll,ll> M;

int phi(int n) {
	if (M.count(n)==1) return M[n];
	int r=n,nn=n;
	for(int i=2;i*i<=n;i++) if (n%i==0){
		r=r/i*(i-1);
		while (n%i==0) n/=i;
	}
	if (n>1) r=r/n*(n-1);
	M[nn]=r;
	return r;
}

ll Euler_qpow(ll a,ll b,ll mod) {
	ll res=1;bool ok=(b>0 && a>=mod);
	while (b>0) {
		if (b&1) {
			res=res*a;
			ok|=(res>=mod);
			res%=mod;			
		}
		a=a*a;
		ok|=(b>1 && a>=mod);
		a%=mod;
		b>>=1;
	}
	return res+mod*ok;
}

ll work(int l,int r,int mod) {
	if (mod==1) return 1;
	if (l==r) return a[l];
	return Euler_qpow(a[l],work(l+1,r,phi(mod)),mod);
}

int main(){
//	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>mod;
	rep(i,1,n+1) cin>>a[i];	
	cin>>q;
	rep(cas,0,q) {
		cin>>l>>r;
		cout<<work(l,r,mod)%mod<<endl;
	}
	return 0;
}

