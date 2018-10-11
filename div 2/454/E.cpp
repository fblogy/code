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

const int N=23;
const int mod=1e9+7;

int n,m,u,v,dp[1<<N],pos,w[N];
bool f[N],a[N][N];
pii pre[1<<N];

bool check() {
	rep(i,1,n+1) if (f[i])
		rep(j,1,n+1) if (f[j]) 
			if (a[i][j]==0) return 1;
	return 0;
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	rep(i,1,n+1) a[i][i]=1;
	rep(i,1,m+1) cin>>u>>v,a[u][v]=a[v][u]=1;
	int s=1<<n;
	fill_n(dp,s,1<<30);
	rep(i,1,n+1) {
		memset(f,0,sizeof(f));
		rep(j,1,n+1) if (a[i][j]==1) f[j]=1;
		dp[1<<(i-1)]=check(); 
	}
	rep(i,1,n+1) rep(j,1,n+1) if (a[i][j]==1) w[i]|=1<<(j-1);
	rep(i,1,s) {
		rep(j,0,n) if ((1<<j)&i) {
			if (dp[i|w[j+1]]>dp[i]+1) dp[i|w[j+1]]=dp[i]+1,pre[i|w[j+1]]=mp(i,j+1);
		}
	}
	cout<<max(dp[s-1]-1,0)<<endl;
	pos=s-1;
	while (dp[pos]>1) {
		cout<<pre[pos].se<<" ";
		pos=pre[pos].fi; 
	}
	return 0;
}

