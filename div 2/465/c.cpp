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
typedef double db;
//---

const int N=100005;
const int mod=1e9+7;

const db eps = 1e-8;

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
};

P read() {
    db x,y;cin >> x >> y;
    return P(x, y);
}

db norm(P p) {
	return p.x * p.x + p.y * p.y;
}

db dis(P p) {
	return sqrt(norm(p));
}

int main(){
	freopen("a.in","r",stdin);
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	db r; P o, p;
	cin >> r;
	o = read();
	p = read();
	if (norm(o - p) >= r * r) {
		printf("%.8f %.8f %.8f", o.x, o.y, r);
	}else if (o == p) {
		printf("%.8f %.8f %.8f", o.x + r / 2, o.y, r / 2);
	}else {
		r = dis(o - p) + r; r /= 2;
		P tmp = (p - o) * (r / dis(o - p));
		tmp = p - tmp;
		printf("%.8f %.8f %.8f", tmp.x, tmp.y, r);
	}
	return 0;
}

