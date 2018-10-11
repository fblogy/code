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

const int N = 1e5 + 7;
string s, t;
int pres[N],pret[N], q, a, b, c, d, num1, num2, lens[N], lent[N], w;

bool check(int x, int y) {
	if (x < y) return 0;
	return ((x - y) % 3) == 0; 
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> s >> t;
	rep(i, 1, sz(s)+1) {
		pres[i] = pres[i-1] + (s[i-1] != 'A');
		if (s[i-1] == 'A') lens[i] = lens[i-1] + 1;else lens[i] = 0;
	}
	rep(i, 1, sz(t)+1) {
		pret[i] = pret[i-1] + (t[i-1] != 'A');
		if (t[i-1] == 'A') lent[i] = lent[i-1] + 1;else lent[i] = 0;
	}
	cin >> q;
	rep(cas, 0, q) {
		cin >> a >> b >> c >> d;
		num1 = pres[b] - pres[a-1];
		num2 = pret[d] - pret[c-1];
		if (num1 > num2 || (num2 - num1) % 2 != 0 || (num1 == num2 && num1 == 0 && !check(b - a + 1, d - c + 1))) cout << 0;
		else {
			//cout << 1;
			if (num1 == num2) {
				if (num1 == 0) cout << 1;
				else cout << check(lens[b], lent[d]);
			}else {
				if (num1 != 0) w = lens[b];else w = b - a + 1;
				if (num1 == 0) w--;
				if (w >= lent[d]) cout << 1;
				else cout << 0;
			}
		} 
	}
	return 0;
}


