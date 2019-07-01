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
const int N = 1e6 + 7;
int n, m, op, p, pp, pos[N], l, r,len;
struct node {
	int l, r;
	/*bool operator > (node b) const{
		int len1, len2, p1, p2;
		if (r == n + 1) len1 = n - l;
		else if (l == 0) len1 = r - 1;
		else len1 = (r - l) / 2;
		if (b.r == n + 1) len2 = n - b.l;
		else if (b.l == 0) len2 = b.r - 1;
		else len2 = (b.r - b.l) / 2;
		if (len1 != len2) return len1 > len2;
		return l < b.l;
	}*/
	bool operator < (node b) const{
		int len1, len2, p1, p2;
		if (r == n + 1) len1 = n - l;
		else if (l == 0) len1 = r - 1;
		else len1 = (r - l) / 2;
		if (b.r == n + 1) len2 = n - b.l;
		else if (b.l == 0) len2 = b.r - 1;
		else len2 = (b.r - b.l) / 2;
		if (len1 != len2) return len1 < len2;
		return l > b.l;
	}  
};
set<int> s;
priority_queue<node> q;

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> m;
	s.insert(0);
	s.insert(n+1);
	rep(i, 1, m+1) {
		cin >> op >> p;
		if (op == 1) {
			while (!q.empty()) {
				l = q.top().l, r = q.top().r;
				if (!s.count(l) || !s.count(r) || *(++s.lower_bound(l)) != r) q.pop();
				else break;
			}
			if (q.empty()) pp = 1;
			else if (l == 0) pp = 1;
			else if (r == n + 1) pp = n;
			else {
				len = (r - l - 1);
				if (len & 1) len = len / 2 + 1;
				else len = len / 2;
				pp = l + len;
			}
			cout << pp << endl;
			s.insert(pp);
			l = *(--s.lower_bound(pp));
			r = *(++s.lower_bound(pp));
			q.push({l, pp});
			q.push({pp, r});
			pos[p] = pp;
		}else {
			auto tmp = s.lower_bound(pos[p]);
			l = *(--tmp);
			++tmp;r = *(++tmp);
			q.push({l, r});
			s.erase(pos[p]);
		}
	}
	return 0;
}


