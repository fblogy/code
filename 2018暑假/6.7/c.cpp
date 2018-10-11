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

priority_queue<int> q;
int s,ans1,ans2,x,a[N],pos,n,siz[N];
vi g[N];
void dfs1(int x) {
	siz[x]=a[x];
	rep(i,0,sz(g[x])){
		int y=g[x][i];
		dfs1(y);
		siz[x]+=siz[y];
	}
	if(ans1!=0&&ans1!=g[0][0]) return;
	if(siz[x]==s/3) {ans1=x;return;}
}

void dfs2(int x) {
	siz[x]=a[x];
	rep(i,0,sz(g[x])){
		int y=g[x][i];
		if (y==ans1) continue;
		dfs2(y);
		siz[x]+=siz[y];
	}
	if(ans2!=0&&ans2!=g[0][0]) return;
	if(siz[x]==s/3) {ans2=x;return;}
}


bool solve(){
	if (s%3!=0) return 0;
	dfs1(0);
	if (ans1==0||ans1==g[0][0]) return 0;
	//de(ans1);
	dfs2(0);
	//de(ans2);
	if (ans2==0||ans2==g[0][0]) return 0;
	printf("%d %d",ans1,ans2);
	return 1;
}

int main(){
	freopen("a.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d%d",&x,&a[i]),g[x].pb(i),s+=a[i];
	//de(s);
	if (!solve()){
		printf("-1");
	}
	return 0;
}
