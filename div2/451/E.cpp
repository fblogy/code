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

int n,x,a[N],w,num,num2;
ll ans;
vi b;

int cal(int x) {
	int y=(int)sqrt(x);
	if (y*y==x) return 0;
	return min(x-y*y,(y+1)*(y+1)-x); 
} 

int main(){
	freopen("a.txt","r",stdin);
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&a[i]);
	rep(i,1,n+1) {
		w=cal(a[i]);
		if (w==0) num++;else b.pb(w);
		if (a[i]==0) num2++;
	}
	sort(b.begin(),b.end());
	if (num<n/2) rep(i,0,n/2-num) ans+=b[i];
	else {
		if (num-n/2>num-num2) ans+=num-n/2-(num-num2)+num-n/2;
		else ans+=num-n/2; 
	}
	printf("%lld",ans);
	return 0;
}
