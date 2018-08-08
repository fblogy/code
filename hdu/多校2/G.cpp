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

const int N=3005;
const int mod=998244353;

ll ans,tmp,f[N],g[N];
int pow2[N*N],n,m,a,b,C[N][N];

void init(){
	C[0][0]=1;
	rep(i,0,N) {
		C[i][0]=1;
		rep(j,1,i+1) 
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	pow2[0]=1;
	rep(i,1,9000001) pow2[i]=(pow2[i-1]<<1)%mod;
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	//return 0;
	while (cin>>n>>m>>a>>b){
		ans=0;
		rep(j,a,n+1) {
			f[j]=1;
			rep(k,a,j) f[j]-=C[j][k]*f[k],f[j]%=mod; 
		}
		rep(j,b,m+1) {
			g[j]=1;
			rep(k,b,j) g[j]-=C[j][k]*g[k],g[j]%=mod; 
		}
		rep(i,a,n+1) {
			tmp=0;
			rep(j,b,m+1) {
				tmp+=g[j]*C[m][j]%mod*pow2[(n-i)*(m-j)];
				tmp%=mod;
			}
			ans+=tmp*f[i]%mod*C[n][i];
			ans%=mod;
		}
		if (ans<0) ans+=mod;
		cout<<ans<<endl;
	}
	return 0;
}
