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

const int N=400005;
const int mod=1e9+7;

ll a[N],f[N],s[N];
int n,t,l,r,pos,h[N];

ll cal(int x) {
	return f[x]-s[x]+a[x+1]*x;
}

bool check(int x,int y,int z,int w) {
	ll ya=cal(x),yb=cal(y),yc=cal(z);
	ll xa=a[x+1],xb=a[y+1],xc=a[z+1];
	if (yc-yb<(xc-xb)*w) return 1;//后比前优的条件 
	return (ya-yb)*(xb-xc)>(yb-yc)*(xa-xb);//队列单调条件 
}

bool check2(int x,int y,int w) {
	ll ya=cal(x),yb=cal(y);
	ll xa=a[x+1],xb=a[y+1];
	return (yb-ya<(xb-xa)*w); //后比前优的条件 
}

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	while (~scanf("%d%d",&n,&t)) {
		rep(i,1,n+1) scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		rep(i,1,n+1) s[i]=s[i-1]+a[i];
		l=1;r=0;
		rep(i,1,n+1) {
			pos=i-t;
			if (pos>=t) {	
				while (l<r && check(h[r-1],h[r],pos,i)) r--;
				h[++r]=pos;
			}
			while (l<r&&check2(h[l],h[l+1],i)) l++;
			if (l>r) f[i]=s[i]-a[1]*i;
			else f[i]=cal(h[l])+s[i]-a[h[l]+1]*i; 
		}
		printf("%lld\n",f[n]);
	} 
	return 0;
}
