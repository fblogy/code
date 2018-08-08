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

const int N=1005;
const int mod=1e9+7;

ll n,W,B,X,f[1005][10005],c[N],cost[N],s;

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>W>>B>>X;
	rep(i,1,n+1) cin>>c[i],s+=c[i];
	rep(i,1,n+1) cin>>cost[i];
	memset(f,-1,sizeof(f));
	rep(i,1,n+1){ 
		f[i][0]=W;
		rep(j,1,s+1){
			if (i>1 && f[i-1][j]!=-1) f[i][j]=min(f[i-1][j]+X,W+B*j);
		}
		rep(k,0,c[i]){
			for(int j=s;j>=1;j--) {
				//if (i>1 && f[i-1][j]!=-1) f[i][j]=max(f[i][j],min(f[i-1][j]+X,W+B*j));
				if (f[i][j-1]-cost[i]>=0) f[i][j]=max(f[i][j],f[i][j-1]-cost[i]);
			}
		}
	}
	for(int i=s;i>=0;i--) if (f[n][i]!=-1) {cout<<i;return 0;}
	return 0;
}

