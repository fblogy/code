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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
//---

const int N=100005;
const int mod=1e9+7;

int n;
vector<int> a[200];

int main(){
	freopen("a.in","r",stdin);
	cin>>n;
	a[0].pb(1);a[1].pb(0);a[1].pb(1);
	rep(i,2,n+1) {
		a[i].pb(0);
		rep(j,0,sz(a[i-1])) a[i].pb(a[i-1][j]);
		rep(j,0,sz(a[i-2])) (a[i][j]+=a[i-2][j])%=2;
	}
	cout<<sz(a[n])-1<<endl;
	rep(i,0,sz(a[n])) cout<<a[n][i]<<(i==sz(a[n])-1?"\n":" ");
	cout<<sz(a[n-1])-1<<endl;
	rep(i,0,sz(a[n-1])) cout<<a[n-1][i]<<(i==sz(a[n-1])-1?"\n":" ");
	return 0;
}
