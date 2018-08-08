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
typedef double db;
//---

const db eps=1e-8;
const int N=100005;
const int mod=1e9+7;

int sign(db x) {
	return (x>eps)-(x<-eps);
}

struct P{
	db x,y;
	P(){}
	P(db _x,db _y) {
		x=_x, y=_y; 
	}
	P operator + (const P &c) const{
		return P(x+c.x,y+c.y);
	}
	P operator - (const P &c) const{
		return P(x-c.x,y-c.y);
	}
	P operator * (const db &c) const{
		return P(x*c,y*c);
	}
	bool operator == (const P &c) const {
        return !sign(x - c.x) && !sign(y - c.y);
    }
    bool operator < (const P &c) const {
        int f = sign(x - c.x);
        return f ? f < 0 : sign(y - c.y) < 0;
    }
};

struct C{
	P o;
	db r;
	C(){}
	C(P o, db r) :o(o),r(r){}
};

db norm(P a) {
	return a.x*a.x+a.y*a.y;
}
db abs(P a) {
	return sqrt(norm(a));
}
db dis(P a,P b) {
	return sqrt(norm(a-b));
}
db cross(P a,P b){
	return a.x*b.y-a.y*b.x;
}
db dot(P a,P b) {
	return a.x*b.x+a.y*b.y;
}
P rot90(P p) {
	return P(-p.y,p.x);
}
db ang(P a,P b){
	return acos(dot(a,b)/abs(a)/abs(b));
}
db ang(P a) {
	return atan2(a.y,a.x);
}

int relCC(C c1,C c2) {
	P p1=c1.o,p2=c2.o;
	db r1=c1.r,r2=c2.r;
	db d=dis(p1,p2);
	if (sign(d)==0 && sign(r1-r2)==0) return 0;
	int x = sign(d - r1 - r2), y = sign(d - fabs(r1 - r2)); 
	if (x == 0) return 2;
	if (y == 0) return 4;
	if (x > 0) return 1;
	if (y < 0) return 5;
	if (y > 0 && x < 0) return 3;
	return -1;
}

bool isCC(C c1, C c2, P &p1, P &p2) {
	db x = norm(c1.o - c2.o),y = ((c1.r * c1.r - c2.r * c2.r) / x + 1) / 2;
	db d = c1.r * c1.r / x - y * y;
	if (sign(d) < 0) return 0;
	if (d < 0) d = 0;
	P q1 = (c2.o - c1.o) * y + c1.o, q2 = rot90((c2.o - c1.o) * sqrt(d));
	p1 = q1 - q2;
	p2 = q1 + q2;
	return 1;
}

void print(P p) {
	cout << p.x << " " << p.y << endl;
}

int n, x, y, r, V, E, u, v, fa[4], num;
C c[3];
vector<P> tmp;

int get(int x) {
	return x==fa[x] ? x : fa[x] = get(fa[x]); 
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	rep(i, 0, n) {
		cin >> x >> y >> r;
		c[i] = C(P(x, y), r);
		fa[i] = i;
	}
	rep(i, 0, n) 
		rep(j, i+1, n) {
			int t = relCC(c[i], c[j]);
			P p1, p2;
			isCC(c[i], c[j], p1, p2);
			if (t == 2 || t == 4) {
				tmp.pb(p1);
			}else if (t == 3) 
				tmp.pb(p1), tmp.pb(p2);
			if (t >= 2 && t <= 4) {
				u = get(i);v = get(j);
				if (v != u) fa[v]=u;
			}
		}
	rep(i, 0, n) {
		if (get(i) == i) num++;
	}
	sort(tmp.begin(), tmp.end());
	V = unique(tmp.begin(), tmp.end()) - tmp.begin();
	rep(i, 0, n) { 
		int num = 0;
		rep(j, 0, V) 
			if (!sign(dis(tmp[j], c[i].o) - c[i].r)) 
				num++;
		E += num;	
	}
	cout << E + 1 + num - V << endl;
	return 0;
}

