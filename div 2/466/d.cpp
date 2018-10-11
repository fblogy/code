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
#define ite iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;
//---

const int N=100005;
const int mod=1e9+7;

int n, a[N], Rl, Rr, Ll, Lr, l, r;
string s;

bool ok1(int pos) {
	rep(i, pos - 4, pos) if (s[i] == '0') return 0;
	return 1;
}

bool ok0(int pos) {
	rep(i, pos - 4, pos) if (s[i] == '1') return 0;
	return 1;
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n;
	rep(i, 0, n) cin >> a[i];
	cin >> s;
	Rl = Ll = -1e9;
	Rr = Lr = 1e9;
	rep(i, 4, n) {
		if (ok1(i) && s[i] == '0') Rr = min(Rr, *min_element(a + i - 4, a + i +1) - 1);
		if (ok1(i) && s[i] == '1') Rl = max(Rl, *min_element(a + i - 4, a + i +1));
		if (ok0(i) && s[i] == '1') Ll = max(Ll, *max_element(a + i - 4, a + i +1) + 1);
		if (ok0(i) && s[i] == '0') Lr = min(Lr, *max_element(a + i - 4, a + i +1));
	}
	l = max(Rl, Ll);
	r = min(Rr, Lr);
	cout << l << " " << l;
	return 0;
}

