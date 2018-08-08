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

const int N=2e3+7;
const int mod=1e9+7;

ll c[N][N],n,m;

void init(){
	rep(i,0,2001) {
		c[i][0]=1;
		rep(j,1,i+1) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}  
} 

int main(){
	freopen("a.in","r",stdin);
	init();
	while (cin>>n>>m) {
		cout<<((c[n+m][m]*c[n+m][m]%mod-c[n+m][m+1]*c[n+m][n+1]%mod)%mod+mod)%mod<<endl;
	}
	return 0;
}

