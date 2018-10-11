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

ll n, k, A, B;

ll work(ll n) {
	if (n < k) return (n - 1) * A;
	ll tmp = n % k;
	ll res = tmp * A;
	ll x = n / k;
	if ((n - tmp - x) * A > B) return res + B + work(x);
	else return (n-1) * A;
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> n >> k >> A >> B;
	cout << work(n);
	return 0;
}

