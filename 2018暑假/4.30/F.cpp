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

int n,nn,k;
ll m;
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
} ans;

node rxuan(node a,int k) {
	return node(a.y,(1<<k)-a.x+1);
}

node lxuan(node a,int k) {
	return node((1<<k)-a.y+1,a.x);
}

node work(int k,ll w){
	if (k==1) {
		if(w==1) return node(1,1);
		if(w==2) return node(1,2);
		if(w==3) return node(2,2);
		if(w==4) return node(2,1);
	}
	ll n=1<<(k-1);
	if (w<=n*n) {
		return rxuan(work(k-1,n*n-w+1),k-1);
	}
	if (w<=2*n*n) {
		node tmp=work(k-1,w-n*n);
		return node(tmp.x,tmp.y+n);
	}
	if (w<=3*n*n) {
		node tmp=work(k-1,w-n*n*2);
		return node(tmp.x+n,tmp.y+n);
	}
	node tmp=lxuan(work(k-1,n*n*4-w+1),k-1);
	return node(tmp.x+n,tmp.y);
}

int main(){
	freopen("a.in","r",stdin);
	scanf("%d%lld",&n,&m);nn=n;
	while (nn>1) {k++;nn>>=1;}
	ans=work(k,m);
	//ans=lxuan(node(2,4),);
	printf("%d %d",ans.x,ans.y);
	return 0;
}
