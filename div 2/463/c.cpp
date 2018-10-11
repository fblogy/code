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
//---

const int N=1000005;
const int mod=1e9+7;

int p[N], n, l, r, A, B, ans1, ans2;

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> A >> B;
	ans1 = ans2 = -1;
	for(int i = 0; i * A <= n; i++) {
		if ((n - i * A) % B == 0) {
			ans1 = i;
			ans2 = (n - i * A) / B;
			break;
		}
	} 
	if (ans1 == -1) cout << -1;
	else {
		l = 1;
		rep(i, 0 , ans1) {
			r = l + A -1;
			rep(j, l , r) p[j] = j + 1;
			p[r] = l;
			l += A;
		}
		rep(i, 0, ans2) {
			r = l + B -1;
			rep(j, l , r) p[j] = j + 1;
			p[r] = l;
			l += B;
		}
		rep(i, 1, n + 1) cout << p[i] << " ";
	}
	return 0;
}

