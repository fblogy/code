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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 505;
int n, m, ok, x, y;
int dx[] = {1, 0 , -1, 0}, dy[] = {0, 1, 0, -1};
string s[N];

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	ok = 1;
	rep(i, 0, n) cin >> s[i];
	rep(i, 0, n)
		rep(j, 0, m) if (s[i][j] == 'S') {
			rep(k, 0, 4) {
				x = i + dx[k];
				y = j + dy[k];
				if (x <0 || x>=n || y <0 || y >=m) continue;
				if (s[x][y] == 'W') {
					ok = 0;
				}
			}
		}
	if (!ok) cout << "No" ;
	else {
		cout << "Yes" << endl;
		rep(i, 0, n)
			rep(j, 0, m) if (s[i][j] == '.') s[i][j] = 'D';
		rep(i, 0, n) cout << s[i] << endl;
	}
	return 0;
}


