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
#define ite iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;
//---

const int N = 50005;
const int mod = 1e9+7;
const int BSZ = 224;

int n, m, B, bl[N], br[N], id[N], c[N], l, r, p, now, cnt[N], num;
int ans1[N], ans2[N], sum;
pair<pii, int> q[N];

void cal(int &x,int y) {
	if (y == 1) sum += x++;
	else sum +=  - --x;
	return;
}

bool cmp(pair<pii, int> a, pair<pii, int> b){
	if (id[a.fi.fi] != id[b.fi.fi]) return id[a.fi.fi] < id[b.fi.fi];
	return a.fi.se < b.fi.se;
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	rep(i, 0, n) cin >> c[i];
	rep(i, 0, m) {
		cin >> l >> r;
		l--; r--;
		q[i] = (mp(mp(l, r), i));
	}
	B = (n - 1) / BSZ + 1;
	rep(i, 0, B) {
		bl[i] = BSZ * i;
		br[i] = min(n, bl[i] + BSZ);
		rep(j, bl[i], br[i]) id[j] = i;
	}
	sort(q, q + m, cmp);
	l = 0; r = 0; cal(cnt[c[0]], 1); num = 1;
	rep(i, 0, m) {
		while (l > q[i].fi.fi) cal(cnt[c[--l]], 1), num++;
		while (r < q[i].fi.se) cal(cnt[c[++r]], 1), num++;
		while (l < q[i].fi.fi) cal(cnt[c[l++]], -1), num--;
		while (r > q[i].fi.se) cal(cnt[c[r--]], -1), num--;
		ans1[q[i].se] = sum; ans2[q[i].se] = num;
	}
	rep(i, 0, m) {
		if (ans1[i] == 0) cout << 0 << "/" << 1 << endl;
		else  {
			ans2[i] = 1ll * ans2[i] * (ans2[i]-1) / 2;
			int g = __gcd(ans1[i], ans2[i]);
			cout << ans1[i] / g << "/" << ans2[i] / g << endl;
		}
	}
	return 0;
}

