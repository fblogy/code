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

const int N=300005;
const int mod=1e9+7;

int n,k,l,r,mid,pos;
ll w;
bool f[N],vis[N];
vi ans;

ll check(int mid) {
	ll res=0;
	rep(i,1,mid+1) res+=mid/i-1;
	return res; 
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	l=1;r=n;pos=-1;
	while (l<=r) {
		mid=l+r>>1;
		ll tmp=check(mid);
		if (tmp>=k) {pos=mid;w=tmp;r=mid-1;}
		else l=mid+1;
	}
	//de(pos);de(w);
	if (pos==-1) cout<<"No";else {	
		rep(i,2,pos+1) if (!f[i])
			for(int j=i+i;j<=pos;j+=i) f[j]=1; 
		rep(i,2,pos+1) if (!f[i]&&w-k>=pos/i){
			w-=pos/i;vis[i]=1;
		}
		rep(i,1,pos+1) if (!vis[i]) ans.pb(i);
		cout<<"Yes\n"<<sz(ans)<<endl;
		rep(i,0,sz(ans)) cout<<ans[i]<<" ";
	}
	return 0;
}

