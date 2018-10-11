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

const int N=1000005;
const int mod=1e9+7;

ll a,b,p,x,inv[N],w,ma,ans,pos;
vector<int> g[N];

ll cal(ll ma,ll w) {
	ll res=0;
	res+=ma/(p-1)*sz(g[w]);ma%=p-1;	
	/*pos=lower_bound(g[w].begin(),g[w].end(),ma)-g[w].begin();
	if (pos!=sz(g[w])) {
		if (g[w][pos]==ma) res+=pos+1;else res+=pos;
	}else res+=pos;*/
	rep(i,0,sz(g[w])) {
		if (g[w][i]<=ma) res++;else break;
	}
	return res;
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b>>p>>x;
	inv[1]=1;
	rep(i,2,p) inv[i]=(p-p/i)*inv[p%i]%p; 
	w=1;rep(i,1,p) { w=w*a%p;g[w].pb(i); }
	rep(i,1,min(p,x)+1) {
		ma=(x-i)/p+1;
		w=b*inv[i]%p;
		ans+=cal(ma+i-1,w)-cal(i-1,w);
	}
	cout<<ans;
	return 0;
}

