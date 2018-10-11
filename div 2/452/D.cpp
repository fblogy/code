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

const int N=200005;
const int mod=1e9+7;

int n,m,len,x;
ll w,ww,ans,y,l,r;

int main(){
//	freopen("a.txt","r",stdin);
	scanf("%d",&n);m=n;
	while (m>0) {
		m/=10;if (m>0) x=m;len++;
	} 
	w=9;ww=1;
	rep(i,1,len) w=w*10+9,ww*=10;
	l=max(1ll,w-n);r=n;
	y=n-ww*x;
	if (l<=r) printf("%lld",(r-l+1)/2);
	else {
		if (len==1) ans=n*(n-1)/2;else {
			ans=ww/2*x*x+(y+1)*x;
			w/=10;l=w-y;r=y;ans+=max(0ll,(r-l+1)/2);
			ans-=x;if (y+1==ww) ans--;
		}
		printf("%lld",ans);
	}
	return 0;
}
