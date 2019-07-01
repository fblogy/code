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
//----

const int N = 1e5 + 7;
const int B = 1e5 + 3;
pii a[N];
bool f[N*4];
vi q[N*4], V;
pair<pii, int> b[N];
vector <pair<pii, int> > P[N];
int cnt, T, n, x, y, Y, nn, z, pos, ans1, ans2;
void ADD(pair<pii, int> x){
	int p = x.fi.fi - x.fi.se + B;
	if (x.se == 0) {
		f[p] == 0 ? cnt++ : cnt--;
		f[p] ^= 1;
	}else {
		cnt -= f[p];
		f[p] = 0;
	}
}

void DEL(pair<pii, int> x){
	int p = x.fi.fi + x.fi.se + B;
	if (q[p].back() == 1) cnt--;
	q[p].pop_back();
	if (q[p].back() == 1) cnt++;
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n >> Y;
		V.clear();cnt = 0;nn = 0;
		rep(i, 1, n+1) {
			cin >> x >> y;
			y = abs(y - Y);
			a[i] = mp(x, y);
			V.pb(x-1);
			V.pb(x+1);
			V.pb(x);
		}
		sort(a+1, a+n+1);
		rep(i, 1, n+1) if (a[i] != a[i-1]) {
			b[++nn] = mp(a[i], 0);
		} else b[nn].se++;
		sort(all(V));
		V.erase(unique(all(V)), V.end());
		n = nn;
		rep(i, 1, n+1) P[b[i].fi.fi].pb(b[i]);
		per(i, 1, n+1) {
			x = b[i].fi.fi; y = b[i].fi.se; z = b[i].se;
			pos = x + y + B;
			if (sz(q[pos]) == 0) q[pos].pb(0);
			if (z == 1) cnt -= q[pos].back(), q[pos].pb(0);
			else {
				q[pos].back() == 0 ? cnt++ : cnt--;
				q[pos].pb(q[pos].back()^1);
			}
		}
		ans1 = ans2 = cnt;
		rep(i, 1, sz(V)) {	
			int tmp = 0;
			rep(j, 0, sz(P[V[i]])) { 
				if (P[V[i]][j].se == 0) tmp++; else tmp += 2;
				DEL(P[V[i]][j]);
			}
			rep(j, 0, sz(P[V[i-1]])) { 
				ADD(P[V[i-1]][j]);
			}
			ans1 = min(ans1, cnt + tmp);
			ans2 = max(ans2, cnt + tmp);
		}
		cout << ans1 << " " << ans2 << endl;
		rep(i, 1, n+1) P[b[i].fi.fi].clear();
		rep(i, 1, n+1) {
			x = b[i].fi.fi; y = b[i].fi.se; z = b[i].se;
			f[x - y + B] = 0;
			q[x - y + B].clear();
		}
	}
	return 0; 
}


