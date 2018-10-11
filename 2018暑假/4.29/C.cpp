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

int ans,n;
ll a[N],b[N],x;

ll gcd(ll a,ll b) {
	if (b==0) return a;
	return gcd(b,a%b);
}

int main(){
	freopen("a.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%lld",&a[i]);
	rep(i,1,n+1) {
		x=0;
		rep(j,i,n+1) {
			x=gcd(a[j],x);
			if (x<=b[j]) break;
			b[j]=x; 
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
