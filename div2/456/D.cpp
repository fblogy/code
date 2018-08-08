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

const int N=100005;
const int mod=1e9+7;

struct node{
	ll w,num;
	int p1,p2;
	node(ll w=0,ll num=0,int p1=0,int p2=0):w(w),num(num),p1(p1),p2(p2){}
	bool operator <(const node &c)const{
		return w<c.w;
	}  
};

priority_queue<node> q;

set<pii> M;

int n,m,w,l,r;
ll a[N],b[N];
ll s,k,ans,p1,p2;

int main(){
	freopen("a.in","r",stdin);
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	cin>>n>>m>>w>>k;
	rep(i,1,n+1) {
		l=max(1,i-w+1);
		r=min(i,n-w+1);
		a[r-l+1]++; 
	}
	rep(i,1,m+1) {
		l=max(1,i-w+1);
		r=min(i,m-w+1);
		b[r-l+1]++; 
	}
	//rep(i,1,n+1) de(a[i]);
	//return 0;
	
	p1=n;p2=m;
	while (a[p1]==0) p1--;
	while (b[p2]==0) p2--; 
	q.push(node(p1*p2,a[p1]*b[p2],p1,p2));
	while (!q.empty()) {
		if(k==0) break;
		node tmp=q.top();q.pop();
		s=min(tmp.num,k);
		ans+=s*tmp.w;
		k-=s;
		p1=tmp.p1-1;p2=tmp.p2-1;
		while (p1>0 && a[p1]==0) p1--;
		while (p2>0 && b[p2]==0) p2--;
		if (p1>0 && M.count(mp(p1,tmp.p2))==0) {
			q.push(node(p1*tmp.p2,a[p1]*b[tmp.p2],p1,tmp.p2));
			M.insert(mp(p1,tmp.p2));
		}
		if (p2>0 && M.count(mp(tmp.p1,p2))==0) {
			q.push(node(tmp.p1*p2,a[tmp.p1]*b[p2],tmp.p1,p2));
			M.insert(mp(tmp.p1,p2));
		}
	}
	//de(ans);
	printf("%.10f",1.0*ans/(n-w+1)/(m-w+1));
	return 0;
}

