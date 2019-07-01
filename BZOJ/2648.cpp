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
typedef int ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----
/*
	
*/
const ll INF = 2147483647;
const int N = 1000005;
int Q, D;
ll now;

int T,n,m,root, op;

struct node{
	int d[2], l, r, mi[2], ma[2];// minp, p, id;
	//void add(int x,int y,int z) {d[0]=x;d[1]=y;id=z;}
};

inline bool cmp(const node &a,const node &b){
	return a.d[Q] < b.d[Q];
}

node a[N],tr[N],ans,v;

inline void update(node &a, const node &b){
	rep(i, 0, D) {
		a.mi[i] = min(a.mi[i], b.mi[i]);
		a.ma[i] = max(a.ma[i], b.ma[i]);
	}
}

inline void insert(int now){
	int k = 0, p = root;
	while (1) {
		update(tr[p], tr[now]);
    	if(tr[now].d[k] >= tr[p].d[k]){
        	if (!tr[p].r) {tr[p].r = now;return;}
			else p = tr[p].r;
    	}else{
        	if (!tr[p].l) {tr[p].l = now;return;}
        	else p = tr[p].l;
    	}
    	k = k ^ 1;
       	//k = (k + 1) % D;
	}
}

int build(int l,int r,int k) {
	if (l>r) return 0;
	int mid = l+r>>1; Q = k;
	nth_element(a+l, a+mid, a+r+1, cmp);
	tr[mid] = a[mid];
	rep(i, 0, D) tr[mid].ma[i] = tr[mid].mi[i] = tr[mid].d[i];
	tr[mid].l = build(l, mid-1, k^1);
	tr[mid].r = build(mid+1, r, k^1);
	if (tr[mid].l) update(tr[mid], tr[tr[mid].l]);
	if (tr[mid].r) update(tr[mid], tr[tr[mid].r]);
	return mid;
}

ll sqr(ll x) {return x*x;}

inline ll get(const node &v, int x) {//估价函数
	if (!x) return INF;
	ll res = 0;
	/*rep(i, 0, D) {
		if (v.d[i] < tr[x].mi[i]) res+=sqr(v.d[i]-tr[x].mi[i]);
		if (v.d[i] > tr[x].ma[i]) res+=sqr(v.d[i]-tr[x].ma[i]);
	}*/
	rep(i, 0, D) {
		if (v.d[i] < tr[x].mi[i]) res += tr[x].mi[i] - v.d[i];
		if (v.d[i] > tr[x].ma[i]) res += v.d[i]-tr[x].ma[i];
	}
	return res;
}
 
inline void check(const node &v,int x) {
	ll dis=0;
	rep(i, 0, D) dis += abs(tr[x].d[i] - v.d[i]);
	/*if (dis < now || (dis == now && tr[x].id < ans.id)) {
		now = dis;
		ans = tr[x];
	}*/
	now = min(dis, now);
}
 
void ask(const node &v,int x) {
	if (!x) return;
	check(v, x);
	ll lm = get(v, tr[x].l), rm = get(v, tr[x].r);
	if (lm < rm) {
		if (lm <= now) ask(v, tr[x].l);
		if (rm <= now) ask(v, tr[x].r);
	}else {
		if (rm <= now) ask(v, tr[x].r);
		if (lm <= now) ask(v, tr[x].l);
	}
}


struct FastIO {
    static const int S = 1310720;
    int wpos;
    char wbuf[S];
    FastIO() : wpos(0) { }
    inline int xchar() {
        static char buf[S];
        static int len = 0, pos = 0;
        if (pos == len) pos = 0, len = fread(buf, 1, S, stdin);
        if (pos == len) return -1;
        return buf[pos++];
    }
    inline int xuint() {
        int c = xchar(), x = 0;
        while (c <= 32) c = xchar();
        for (; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x;
    }
    inline int xint() {
        int c = xchar(), x = 0, s = 1;
        while (c <= 32) c = xchar();
        if (c == '-') s = -1, c = xchar();
        for (; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x * s;
    }
    inline void xstring(char *s) {
        int c = xchar();
        while (c <= 32) c = xchar();
        for (; c >  32; c = xchar()) *s++ = c;
        *s = 0;
    }
    inline void wchar(int x) {
        if (wpos == S) fwrite(wbuf, 1, S, stdout), wpos = 0;
        wbuf[wpos++] = x;
    }
    inline void wint(int x) {
        if (x < 0) wchar('-'), x = -x;
        char s[24];
        int n = 0;
        while (x || !n) s[n++] = '0' + x % 10, x /= 10;
        while (n--) wchar(s[n]);
    }
    inline void wstring(const char *s) {
        while (*s) wchar(*s++);
    }
    ~FastIO() {
        if (wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
    }
} io;

int main(){
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int num = 0;
	D = 2;
	n = io.xint();
	m = io.xint();
	rep(i, 1, n+1) 
		rep(j, 0, 2) a[i].d[j] = io.xint();
	root = build(1, n, 0);
	rep(cas, 1, m+1) {
		now = INF;
		op = io.xint();
		v.d[0] = io.xint();
		v.d[1] = io.xint();
		if (op == 1) {
			tr[++n] = v;
			a[n] = v;
			rep(i, 0, D) tr[n].mi[i] = tr[n].ma[i] = tr[n].d[i];
			insert(n);
			//num++;
			//if (num % 50000 == 0) root = build(1, n, 0);
		}else {
			ask(v, root);
			io.wint(now);
			io.wchar('\n');
		}
	}
}
