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
int n,m;
ll a[N],b[N],ans;

ll solve(int p) {
	ll res=-1ll<<60;
	rep(i,1,n+1) if (i!=p)
		rep(j,1,m+1) res=max(res,a[i]*b[j]);
	return res;
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	rep(i,1,n+1) cin>>a[i];
	rep(i,1,m+1) cin>>b[i];
	ans=solve(1);
	rep(i,2,n+1) ans=min(ans,solve(i));
	cout<<ans<<endl;
	return 0;
}

