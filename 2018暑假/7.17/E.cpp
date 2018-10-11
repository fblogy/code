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

int tr[N*4][2],a[N],tmp[5],n,s,ans,k,b[N],w,mi[30],pos[N];
priority_queue<int> q[20];

void build(int l,int r,int now,int dep){
	if (l==r) {
		tr[now][0]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,now*2,dep-1);
	build(mid+1,r,now*2+1,dep-1);
	tmp[0]=tr[now*2][0];tmp[1]=tr[now*2][1];
	t-mp[2]=tr[now*2+1][0];tmp[3]=tr[now*2+1][1];
	sort(tmp,tmp+4);
	tr[now][0]=tmp[3];
	tr[now][1]=tmp[2];
	mi[dep]=min(mi[dep],tr[now][1]);
}



int main(){
//	freopen("a.in","r",stdin);
	cin>>n;s=1<<n;
	rep(i,1,s+1) cin>>a[i];
	rep(i,0,30) mi[i]=1<<30;
	build(1,s,1,n);
	rep(i,1,s+1) {
		ans=0;
		rep(j,1,n+1) {
			if (mi[j]>=a[i]) break;
			ans=j;
		}
		pos[a[i]]=ans;
	}
	rep(i,1,s+1) cout<<pos[i]<<" ";
	return 0;
}

