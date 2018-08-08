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

vi g[N];
int ans,n,m,u,v,du[N],a[N];
bool ok;
queue<int> q1,q2;

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	rep(i,0,n) cin>>a[i];
	rep(i,0,m) {
		cin>>u>>v;
		g[v].pb(u);
		du[u]++;
	}
	rep(i,0,n) if (du[i]==0) {
		if(a[i]==0) q1.push(i);
		else q2.push(i);
	}
	while (1) {
		while (!q1.empty()) {
			u=q1.front();q1.pop();
			rep(i,0,sz(g[u])) {
				v=g[u][i];
				du[v]--;
				if (du[v]==0) {
					if (a[v]==0) q1.push(v);else q2.push(v);
				}
			}
		}
		ok=0;
		while (!q2.empty()) {
			ok=1;
			u=q2.front();q2.pop();
			rep(i,0,sz(g[u])) {
				v=g[u][i];
				du[v]--;
				if (du[v]==0) {
					if (a[v]==0) q1.push(v);else q2.push(v);
				}
			}
		}
		if (ok) ans++;
		if (q1.empty()&&q2.empty()) break; 
	}
	cout<<ans;
	return 0;
}

