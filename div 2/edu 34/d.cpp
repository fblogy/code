#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(a) a.size()
#define de(a) cout<<#a<<" = "<<a<<endl;

using namespace std;

const int N=200005;
const int mod=1e9+7;

int n,a[N];
long long s;
long double ans;
map<int,int> g;
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%d",&a[i]);
		if (g.count(a[i])==0) g[a[i]]=1;else g[a[i]]++;
		s+=a[i];
	}
	rep(i,1,n+1) {
		s-=a[i];
		ans+=s-1ll*a[i]*(n-i);
		g[a[i]]--;
		if (g.count(a[i]-1)==1) {
			ans+=g[a[i]-1];
		}
		if (g.count(a[i]+1)==1) {
			ans-=g[a[i]+1];
		}
	}
	//long long ans2=(long long)ans;
	//printf("%lld",ans2);
	printf("%.0Lf",ans);
	return 0;
}
