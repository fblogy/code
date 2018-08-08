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

int pos,T;
string s;
ll t;
map<ll,ll> M;

ll qpow(ll a,ll b,ll mod=1e18) {
	ll res=1;
	while (b>0) {
		if (b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
} 

ll phi(int n){
	if (M.count(n)==1) return M[n];
	int r=n,nn=n;
	for (int i=2;i*i<=n;i++) if (n%i==0) {
		r=r/i*(i-1);
		while (n%i==0) n/=i;
	}
	if (n>1) r=r/n*(n-1);
	M[nn]=r;
	return r;  
}

ll work(int n,int mod) {
	if (n==pos) {
		if (s[n]=='0') return (t+1)%mod;
		if (s[n]=='1') return (t+1)*2%mod;
		return (3*qpow(2,t+1,mod)-3+mod)%mod;
 	}
	if (s[n]=='0') {
		return (work(n-1,mod)+1)%mod;
	}
	else if (s[n]=='1') {
		return (work(n-1,mod)+1)*2%mod;
	}
	ll Phi=phi(mod),w;	
	w=(work(n-1,Phi)+1)%Phi+Phi;
	return (3*qpow(2,w,mod)-3+mod)%mod;
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	rep(cas,0,T) {
		cin>>s;
		t=0;pos=-1;
		rep(i,0,sz(s)) {
			if (s[i]=='0') {if (t+1>=mod) {pos=i;break;}t++;}
			else if (s[i]=='1') {if ((t+1)*2>=mod) {pos=i;break;}t=(t+1)*2;}
			else if (s[i]=='2') {
				if (t>=30) {pos=i;break;}
				t=3*qpow(2,t+1)-3;
			}
		}
		if (pos==-1) cout<<t%mod<<endl;else 
		cout<<work(sz(s)-1,mod)<<endl;
	}
	return 0;
}

