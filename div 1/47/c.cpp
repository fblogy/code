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
/*const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}*/
//----

const int N = 4e5 + 7;
const db eps = 1e-8;
const db pi = acos(-1);

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

//负数 -1 零  0 正数  1
int sign(db x) {
    return (x > eps) - (x < -eps);
}

struct P {
    db x,y;
    P() {}
    P(db x, db y) {
        this->x = x;
        this->y = y;
    }
    P operator + (const P &c) const {
        return P(x + c.x, y + c.y);
    }
    P operator - (const P &c) const {
        return P(x - c.x, y - c.y);
    }
    P operator * (const db &c) const {
        return P(x * c, y * c);
    }
    P operator / (const db &c) const {
        return P(x / c, y / c);
    }
    bool operator < (const P &c) const {
        int f = sign(x - c.x);
        return f ? f < 0 : sign(y - c.y) < 0;
    }
    bool operator == (const P &c) const {
        return !sign(x - c.x) && !sign(y - c.y);
    }
    bool operator != (const P &c) const {
        return !(*this == c);
    }
    bool operator > (const P &c) const {
        return !(*this == c) && !(*this < c);
    }
} p[N], g[N];

db cross(P a, P b) {
    return a.x * b.y - b.x * a.y;
}

int convexhull(P *p, int n, P *ch) {
	sort(p, p + n);
	int m = 0;
	rep(i, 0, n) {
		while(m > 1 && sign(cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= 0) --m;
		ch[m++] = p[i];
	}
	int k = m;
	for(int i = n - 2; i >= 0; --i) {
		while(m > k && sign(cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= 0) --m;
		ch[m++] = p[i];
	}
	if(n > 1) --m;
	return m;
}

int n, x, y, xx, yy, m, ans;

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 1, n+1) {
		cin >> x >> y;
		rep(i, 0, 4) {
			xx = x + dx[i]; yy = y + dy[i];
			p[m++] = P(xx, yy);
		}
	}
	m = convexhull(p, m, g);
	p[m] = p[0];
	rep(i, 0, m) {
		ans += max(abs(g[i].x - g[i+1].x), abs(g[i].y - g[i+1].y));
	}
	cout << ans;
	return 0;
}


