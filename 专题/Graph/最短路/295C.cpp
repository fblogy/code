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

const int N = 55;
int d[N][N][2], k, s1, s2, n, x, y, z, w[N][N][2], c[N][N];

void init(){
	c[0][0] = 1;
	rep(i, 1, N) {
		c[i][0] = 1;
		rep(j, 1, i+1) c[i][j] = add(c[i-1][j], c[i-1][j-1]); 
	}
}

void bfs(int a, int b, int o) {
	queue<pair<pii, int> > q; 
	q.push(mp(mp(a, b), o));
	while (!q.empty()) {
		auto t = q.front(); q.pop();
		a = t.fi.fi; b = t.fi.se; o = t.se;
		rep(i, 0, a+1)
			rep(j, 0, b+1) if (i + j > 0 && i + 2 * j <= k) {
				x = s1 - a + i; y = s2 - b + j; z = o ^ 1;
				if (d[x][y][z] == -1) {
					d[x][y][z] = d[a][b][o] + 1;
					w[x][y][z] = mul(w[a][b][o], mul(c[a][i], c[b][j]));
					q.push(mp(mp(x, y), z));
				}else if (d[x][y][z] == d[a][b][o] + 1) {
					w[x][y][z] = add(w[x][y][z], mul(w[a][b][o], mul(c[a][i], c[b][j])));
				} 
			}
	}
	return;
}

int main() {
	//freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> k;
	memset(d, -1, sizeof(d));
	rep(i, 1, n+1) {
		cin >> x;
		if (x == 50) s1++; else s2++;
	}
	k /= 50;
	init();
	d[s1][s2][0] = 0;
	w[s1][s2][0] = 1;
	bfs(s1, s2, 0);
	cout << d[s1][s2][1] << endl;
	cout << w[s1][s2][1];
	return 0;
}


