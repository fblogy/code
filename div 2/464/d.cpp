#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
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

int fa[500], n, x, y;
string a, b;
vector<pii> ans;
int get(int x) {
	return x == fa[x] ? x : fa[x] = get(fa[x]);
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	rep(i, 1, 300) fa[i] = i;
	cin >> n >> a >> b;
	rep(i, 0 ,n) {
		x = get(a[i]); y = get(b[i]);
		if (x != y) {
			fa[x] = y;
			ans.pb(mp(x, y));
		}
	}
	cout << sz(ans) << endl;
	rep(i, 0 , sz(ans)) {
		cout << (char)ans[i].fi << " " << (char)ans[i].se << endl;
	} 
	return 0;
}

