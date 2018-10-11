#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
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

const int N = 200005;
const int mod = 1e9+7;

int m, num, n, u;
vi p[N];
string s;
queue<int> q1, q2;

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> s;
	rep(i, 0, sz(s)) {
		if (s[i] == '0') {
			if (q2.empty()) {
				num++;
				q1.push(num);
				p[num].pb(i+1);
			}else {
				u = q2.front();
				q2.pop();
				q1.push(u);
				p[u].pb(i+1);
			}
		}else {
			if (q1.empty()) {
				cout << -1;
				return 0;
			}else {
				u = q1.front();
				q1.pop();
				q2.push(u);
				p[u].pb(i+1);
			}
		}
	}
	if (!q2.empty()) {
		cout << -1;
		return 0;
	}
 	cout << num << endl;
	rep(i, 1, num+1) {
		cout << sz(p[i]) << " ";
		rep(j, 0, sz(p[i])) cout << p[i][j] << " ";
		cout << endl;
	} 
	return 0;
}

