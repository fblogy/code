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

int a[8],b[8][8],sx,sy,tx,ty,ans,num;
ll w[8],ha;
set <ll> q;

bool check(int o) {
	rep(i,1,5) rep(j,1,a[i]+1){
		if (b[i][j]==o&&b[i][j+1]==o&&b[i][j-1]==o) return 1;
		if (b[i+1][j]==o&&b[i][j]==o&&b[i-1][j]==o) return 1;
		if (b[i][j]==o&&b[i-1][j-1]==o&&b[i+1][j+1]==o) return 1;
		if (b[i][j]==o&&b[i-1][j+1]==o&&b[i+1][j-1]==o) return 1;
	}
	return 0;
}

void dfs(bool o) {
	if (a[tx]==ty) {	
		ha=0;
		rep(i,1,5) ha=ha*pow(3,4)+w[i];
		if (check(0)&&q.count(ha)==0) {ans++;q.insert(ha);}
		return;
	}
	if (check(1) || check(0)) return;
	rep(i,1,5) if (a[i]<4){
		if (o==1 && i==tx && a[i]==ty-1) continue;
		ll tmp=a[i];
		a[i]++;b[i][a[i]]=o;w[i]+=(o+1)*pow(3,a[i]-1);
		dfs(o^1);
		a[i]--;b[i][a[i]+1]=-1;w[i]-=(o+1)*pow(3,a[i]);
	}
}

int main(){
//	freopen("a.in","r",stdin);
	memset(b,-1,sizeof(b));
	scanf("%d%d%d",&sx,&ty,&tx);
	a[sx]=1;b[sx][1]=1;w[sx]=1;
	dfs(0);
	printf("%d",ans);
	return 0;
}
