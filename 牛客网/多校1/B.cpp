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
//const int mod=1e9+7;

int n,mod;
ll f[N],g[N];

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (cin>>n>>mod){
		f[0]=1%mod;f[1]=0;f[2]=1%mod;g[2]=1%mod;
		rep(i,3,n+1) {
			f[i]=g[i-1]+(i-1)*f[i-2];
			f[i]%=mod;
			g[i]=i*g[i-1]+f[i-2]*(1ll*i*(i-1)/2%mod);
			g[i]%=mod;
		}
		cout<<f[n]<<endl; 
	}
	return 0;
}

