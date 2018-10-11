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

const int N = 100005;
const int mod = 1e9+7;

ll p, y;
bool ok;
int ans;

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> p >> y;
	ans = -1;
	if (p * p < y) {
		for (int i = y; i > p; i--) {
			ok = 1;
			rep(j, 2, p+1) if (i % j == 0) {ok = 0;break;}
			if (ok) {ans = i; break;}
		}
	}else {
		for (int i = y; i > p; i--) {
			ok = 1;
			for(int j = 2; j * j <= y; j++) if (i % j == 0) {ok = 0;break;}
			if (ok) {ans = i; break;}
		}
	}
	cout << ans;
	return 0;
}

