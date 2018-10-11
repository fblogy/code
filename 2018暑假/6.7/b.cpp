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

priority_queue<int> q;
int n;
ll a[N],ans,mi,t,ts,tf;

int main(){
//	freopen("a.in","r",stdin);
	scanf("%lld%lld%lld%d",&ts,&tf,&t,&n);
	rep(i,0,n) scanf("%lld",&a[i]);
	if(a[0]>ts) {printf("%d",ts);return 0;}
	ans=a[0]-1;mi=(ts-a[0]+1);
	rep(i,0,n-1) {
		if(ts+t*(i+1)+t>tf) break;
		if(ts+t*(i+1)<a[i+1]) {
			ans=ts+t*(i+1);
		
			mi=0;
				break;
		}else if(mi>(ts+t*(i+1)-(a[i+1]-1))) {	
				mi=ts+t*(i+1)-(a[i+1]-1);
				ans=a[i+1]-1;	
		}
	}
	if (mi>0&&ts+t*(n+1)<=tf) ans=ts+t*n; 
	printf("%lld",ans);
	return 0;
}
