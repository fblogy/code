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

int a[N],n,m,k;
ll sum[N],dp[10][N];

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (cin>>n>>m>>k){
		rep(i,0,10) fill_n(dp[i],n+1,0);
		fill_n(sum,n+1,0);
		rep(i,1,n+1) cin>>a[i];
		sum[0]=1;
		rep(i,1,n+1) {
			for(int j=i;j>=1&&j>=i-m;j--) {
				sum[j]+=sum[j-1]-dp[a[i]][j];
				//if (pre[i]) sum[i][j]-=sum[pre[i]-1][j-1];
				sum[j]%=mod;
				dp[a[i]][j]=sum[j-1]; 
			} 
		}
		if (sum[n-m]<0) sum[n-m]+=mod;
		cout<<sum[n-m]<<endl;
	}
	return 0;
}

