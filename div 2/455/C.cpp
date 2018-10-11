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

const int N=5005;
const int mod=1e9+7;

int n,ans,sum,dp[N][N],p;
string s[N];

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	cin>>s[1];
	if (s[1][0]=='f') dp[1][1]=1;else dp[1][0]=1;
 	rep(i,2,n+1) {
		cin>>s[i];
		p=(s[i][0]=='f');
		if (s[i-1][0]=='f') {
			rep(j,0,i) dp[i][j+p]=dp[i-1][j];
		}else {
			sum=0;
			for(int j=i;j>=0;j--) {
				sum+=dp[i-1][j];sum%=mod;
				dp[i][j+p]+=sum;
				dp[i][j+p]%=mod;
			}
		}
	}
	rep(i,0,n+1) ans+=dp[n][i],ans%=mod;
	cout<<ans<<endl;
	return 0;
}

