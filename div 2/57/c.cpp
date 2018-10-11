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

int a, b;
ll t;
string s1, s2, ans;

int val(char s) {
	if (s >= '0' && s <= '9') return s - '0';
	else return s - 'A' + 10;
}

char eval(int x) {
	if (x <= 9) return x + '0';
	else return x - 10 + 'A';
}

ll get(string &s, int d) {
	ll res = 0;
	rep(i, 0, sz(s)) res = res * d + val(s[i]);
	return res;
}

string solve2(ll x, int d) {
	string res = "";
	if (x == 0) res = "0";
	while (x > 0) res += eval(x % d), x /= d;
	reverse(all(res));
	return res;
}

string solve(ll x) {
	if (x == 0) return "";
	if (x == 1) return "I";
	if (x == 5) return "V";
	if (x == 10) return "X";
	if (x == 50) return "L";
	if (x == 100) return "C";
	if (x == 500) return "D";
	if (x == 1000) return "M";
	if (x <= 5) {
		if (x == 2) return "II"; 
		if (x == 3) return "III"; 
		if (x == 4) return "IV"; 
	}
	if (x <= 10) {
		if (x < 9) return "V" + solve(x - 5);
		else return solve(10 - x) + "X";
	}
	if (x <= 50) {
		if (x < 40) return "X" + solve(x - 10);
		else return "XL" + solve(x - 40);
	}
	if (x <= 100) {
		if (x < 90) return "L" + solve(x - 50);
		else return "XC" + solve(x - 90);
	}	
	if (x <= 500) {
		if (x < 400) return "C" + solve(x - 100);
		else return "CD" + solve(x - 400);
	}	
	if (x <= 1000) {
		if (x < 900) return "D" + solve(x - 500);
		else return "CM" + solve(x - 900);
	}	
	return "M" + solve(x - 1000);
}

int main() {
	freopen("a.in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> a >> s1;
	cin >> s2;
	t = get(s2, a);
	if (s1 == "R") {
	//	de(t);
		ans = solve(t);
	}else {
		b = get(s1, 10);
		ans = solve2(t, b);
	}
	cout << ans;
	return 0;
}


