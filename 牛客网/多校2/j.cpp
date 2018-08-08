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

struct node{
	int x1,x2,y1,y2,w;
	node(int x1=0,int y1=0,int x2=0,int y2=0,int w=0):x1(x1),y1(y1),x2(x2),y2(y2),w(w){};
}op[N];

int n,m,T,aa,b,c,d,w,ans;
vi s[N],a[N];


void add(int cas) {
	s[op[cas].x1][op[cas].y1]++;
	s[op[cas].x2+1][op[cas].y1]--;
	s[op[cas].x1][op[cas].y2+1]--;
	s[op[cas].x2+1][op[cas].y2+1]++;	
}

int main(){
//	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>T;
	rep(i,0,n+2) a[i]=vi(m+1,0);
	rep(i,1,n+1) rep(j,1,m+1) cin>>a[i][j];
	rep(i,0,T) {
		cin>>aa>>b>>c>>d>>w;
		op[i]=node(aa,b,c,d,w);
	}
	rep(k,0,20){
		rep(i,0,n+2) s[i]=vi(m+2,0);
		int w=1<<k;
		rep(cas,0,T) if (op[cas].w&w) add(cas);
		rep(i,1,n+1) rep(j,1,m+1) {
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
			if (s[i][j]>0) a[i][j]^=w;
		}
	}
	rep(i,1,n+1) rep(j,1,m+1) if (a[i][j]) ans++;
	cout<<ans;
	return 0;
}
