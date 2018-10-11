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

int w, f[N], k, ok, n;
string s, t;

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> k;
	cin >> s;
	w = 1 << 30;
	rep(i, 0, sz(s)) f[s[i]] = 1, w = min(w, (int)s[i]);
	t = "";
	//de();
	if (k > sz(s)) {
		t = s;
		rep(j, 0, k - sz(s)) t += w;
 	}else {
		for (int i = k-1;i >= 0; i--) {
			ok = 0;
			rep(j, s[i]+1, 'z'+1) if (f[j]) {
				ok = j;
				break;
			}
			if (ok) {
				rep(j, 0, i) t += s[j];
				t += ok;
				rep(j, i+1, k) t += w;
				break;
			}
		} 
	}
	cout << t;
	return 0;
}

