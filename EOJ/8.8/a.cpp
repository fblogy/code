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
typedef double db;
//---

const int N=105;
const int mod=1e9+7;

int n, m, n2, m2, a[N][N], b[N][N], tmp;

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	rep(i, 1, n+1) rep(j, 1, m+1) cin >> a[i][j];
	cin >> n2 >> m2;
	rep(i, 1, n2+1) rep(j, 1, m2+1) cin >> b[i][j];
	rep(i, 1, n + 2 -n2) {
		rep(j, 1, m + 2 - m2) {
			if (i + n2 -1 <= n && j + m2 -1 <= m) {
				tmp = 0;
				rep(k, 1, n2+1) rep(l, 1, m2+1) tmp += a[i + k - 1][j + l -1] * b[k][l];
				cout << tmp;
				if (j != m +1 -m2) cout<<" "; 
			}
		}
		cout << endl;
	}
	return 0;
}

