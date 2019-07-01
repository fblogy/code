// 求补图的联通性加生成树知识 
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 3e5 + 8;
int cnt, cnt1, u, v, f[N], k, now, n, m;
set<int> g[N], S;

void bfs(int u) {
	queue<int> q;
	q.push(u);
	while (!q.empty()) {
		int x = q.front(); q.pop(); f[x] = u;
		vi tmp;
		for(auto v : S) if (!g[x].count(v)) tmp.pb(v);
		for (auto v : tmp) {
			S.erase(v);
			q.push(v);
		}
	}
}

int get(int x) {
	if (x == f[x]) return x;
	return f[x] = get(f[x]);
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m >> k;
	rep(i, 1, m+1) {
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	rep(i, 1, n+1) f[i] = i;
	rep(i, 2, n+1) S.insert(i);
	while (1) {
		if (sz(S) == 0) break;
		now = *S.begin();
		S.erase(now);
		bfs(now);
		cnt1++;
	}
	rep(i, 2, n+1) if (!g[1].count(i)){
		if (get(1) != get(i)) f[get(i)] = get(1), cnt++;
	}
	if (cnt != cnt1 || cnt > k || n - 1 - sz(g[1]) < k) cout << "impossible";else cout << "possible";
	return 0;
}


