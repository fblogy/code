//一边度为2的二分图匹配 
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

const int N = 2e6 + 7;
int du[N], a[N], b[N];
vi V, g[N];
int n, m, cnt1, cnt2, now, u, v, vis[N], tid;
queue<int> q;
map<int, int> M;

int main() {
	//freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n+1) {
		cin >> a[i] >> b[i];
		V.pb(a[i]);
		V.pb(b[i]);
	}
	sort(all(V));
	V.erase(unique(all(V)), V.end());
	for (auto v : V) M[v] = tid++;
	rep(i, 1, n+1) {
		a[i] = M[a[i]];
		g[a[i]].pb(i);
		du[a[i]]++;
		b[i] = M[b[i]];
		g[b[i]].pb(i);
		du[b[i]]++;
	}
	m = sz(V);
	if (m < n) {cout << -1; return 0;}
	cnt1 = n;
	now = 0;
	while (cnt2 != cnt1) {
		if (now == m) {cout << -1; return 0;}
		if (du[now] == 1) q.push(now);
		if (du[now] > 0) cnt2++;
		now++;
		while (!q.empty()) {
			u = q.front(); q.pop(); cnt2--;
			for (auto v : g[u]) if (!vis[v]) {
				vis[v] = 1;
				cnt1--;		
				du[a[v]]--;
				if (du[a[v]] == 1 && a[v] < now) q.push(a[v]);
				du[b[v]]--;
				if (du[b[v]] == 1 && b[v] < now) q.push(b[v]);
			}
		}
	}
	cout << V[now-1];
	return 0;
}


