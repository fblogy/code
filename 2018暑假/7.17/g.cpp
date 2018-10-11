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

int a[N],f[N],num,n,k,ma,now;
ll ans;

int main(){
//	freopen("a.in","r",stdin);
	cin>>n>>k;
	rep(i,1,n+1) cin>>a[i];
	rep(i,1,k+1) {
		f[a[i]]++;if (f[a[i]]==1) num++;
	}
	ma=num;ans=1;
	rep(i,2,n+2-k) {
		f[a[i+k-1]]++;num+=(f[a[i+k-1]]==1);
		f[a[i-1]]--;num-=(f[a[i-1]]==0);
		ma=max(ma,num);
	}
	ans=1;
	memset(f,0,sizeof(f));now=0;
	rep(i,1,n+1) {
		if (i-k>0) {
			f[a[i-k]]--;if (f[a[i-k]]==0) now--;
		}
		f[a[i]]++;
		if (f[a[i]]==1) {
			(ans*=(ma-now))%=mod;
			now++;
		}
	}
	cout<<ans;
	return 0;
}

