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

const int N = (3e5 + 7) * 33;
int n, a[N], x;
// 'a' .. 'z'
// !!!! : ini() 
struct Trie {
	static const int N = ::N;
	int son[N][2], _, ch, siz[N];
	int ne() { fill_n(son[_], 2, -1); return _++; }
	void ini() { _ = 0; ne(); }
	void insert(const int &s) {
    	int u = 0;siz[u]++;
    	per(i, 0, 31)  {
    		ch = (pw(i) & s) > 0;
			int &v = son[u][ch];
    		if (!~v) v = ne();
    		u = v;
    		siz[u]++;
    	}
  	}
  	int find(const int &s) {
		int u = 0; siz[u]--; int res = 0;
    	per(i, 0, 31)  {
    		ch = (pw(i) & s) > 0;
			if (son[u][ch] != -1 && siz[son[u][ch]] > 0) {
				u = son[u][ch];
				if (ch) res |= pw(i);
			}else {
				u = son[u][ch^1];
				if (ch^1) res |= pw(i);
			}
    		siz[u]--;
    	}
    	return res ^ s;
	}
} tree;


int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	tree.ini();
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, n+1) cin >> x, tree.insert(x);
	rep(i, 1, n+1) cout << tree.find(a[i]) << " ";
	return 0;
}


