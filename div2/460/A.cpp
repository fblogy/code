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

int n,m,a,b;
double ans;

int main(){
//	freopen("a.in","r",stdin);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>n>>m;
	rep(i,1,n+1) {
		cin>>a>>b;
		if (i==1) ans=1.0*m/b*a;
		else ans=min(ans,1.0*m/b*a);
	}
	printf("%.7f",ans);
	return 0;
}

