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

int n,m,nx,ny,l1,r1,tr[N*4],tmp;

vi X,Y;

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
} a[N],s,t;

bool cmp(node a,node b) {
	if (a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}

void xuan(){
	int mx=-1,my=-1;
	rep(i,1,n+1) mx=max(mx,a[i].x);
	rep(i,1,n+1) my=max(my,a[i].y);
	if (s.x>t.x) {
		s.x=mx-s.x;
		t.x=mx-t.x;
		rep(i,1,n+1) a[i].x=mx-a[i].x;
	}
	if (s.y>t.y) {
		s.y=my-s.y;
		t.y=my-t.y;
		rep(i,1,n+1) a[i].y=my-a[i].y;
	}
	//de(t.x);de(t.y);
	rep(i,1,n+1) if (a[i].x>=s.x&&a[i].x<=t.x&&a[i].y<=t.y&&a[i].y>=s.y) a[++m]=a[i];
	rep(i,1,m+1) X.pb(a[i].x),Y.pb(a[i].y);
	sort(X.begin(),X.end());nx=unique(X.begin(),X.end())-X.begin();
	sort(Y.begin(),Y.end());ny=unique(Y.begin(),Y.end())-Y.begin();
	sort(a+1,a+m+1,cmp);
}

void change(int l,int r,int now) {
	if (l1<=l && r1>=r) {
		tr[now]=max(tr[now],tmp);
		return;
	}
	int mid=(l+r)>>1;
	if (l1<=mid) change(l,mid,now*2);
	if (r1>mid) change(mid+1,r,now*2+1);
	tr[now]=max(tr[now*2],tr[now*2+1]);
}

void ask(int l,int r,int now) {
	if (l1<=l && r1>=r) {
		tmp=max(tr[now],tmp);
		return;
	}
	int mid=(l+r)>>1;
	if (l1<=mid) ask(l,mid,now*2);
	if (r1>mid) ask(mid+1,r,now*2+1);
}

int main(){
	freopen("a.in","r",stdin);
	scanf("%d",&n);
	scanf("%d%d%d%d",&s.x,&s.y,&t.x,&t.y);
	rep(i,1,n+1) scanf("%d%d",&a[i].x,&a[i].y);
	a[n+1]=node(s.x,s.y);a[n+2]=node(t.x,t.y);n+=2;
	xuan();
	rep(i,1,m+1) {
		l1=1;r1=lower_bound(Y.begin(),Y.begin()+ny,a[i].y)-Y.begin();r1++;
		tmp=0;ask(1,ny,1);tmp++;
		l1=r1;change(1,ny,1);
	}
	printf("%d",tmp-2);
	return 0;
}
