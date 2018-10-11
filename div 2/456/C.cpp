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

int n,m,num;
ll Bou,Inc,Dma,t,id,h,l,r,S[N*5],T[N*5],ans;
vector<pii> q[N];
vector<pii> P;

struct node{
	ll ma,st,reg;
	node(ll ma=0,ll st=0,ll reg=0):ma(ma),st(st),reg(reg){}
} a[N];

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>Bou>>Inc>>Dma;
	rep(i,0,n) cin>>a[i].ma>>a[i].st>>a[i].reg;
	rep(i,0,n) q[i].pb(mp(0,a[i].st));
	rep(i,0,m) {
		cin>>t>>id>>h;
		q[id-1].pb(mp(t,h));
	}
	rep(i,0,n) if (a[i].ma>Dma) {
		sort(q[i].begin(),q[i].end());
		rep(j,0,sz(q[i])) {
			l=q[i][j].fi;h=q[i][j].se;
			if (h<=Dma) {
				if (a[i].reg==0) {
					P.pb(mp(l,1));
					if (j!=sz(q[i])-1) P.pb(mp(q[i][j+1].fi,-1));
				}else {
					r=(Dma-h)/a[i].reg+l;
					if (j!=sz(q[i])-1) r=min(r,1ll*q[i][j+1].fi-1);
					P.pb(mp(l,1));
					P.pb(mp(r+1,-1));
				}
			} 	
		}
 	}else P.pb(mp(0,1));
 	sort(P.begin(),P.end());
 	rep(i,0,sz(P)) {
		if (i==0||P[i].fi!=P[i-1].fi) {S[++num]=P[i].se;S[num]+=S[num-1];T[num]=P[i].fi;}
		else S[num]+=P[i].se; 
	}
	if(S[num]>0&&Inc>0) cout<<-1;else {
		rep(i,1,num+1){
			ans=max(ans,S[i-1]*(Bou+Inc*(T[i]-1)));
			ans=max(ans,S[i]*(Bou+Inc*T[i]));
		}
		cout<<ans;
	}
	return 0;
}

