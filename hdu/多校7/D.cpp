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
const db eps = 1e-8;
int c[20][20], n, q, A, B, m;
db ans, l[20], now, t, w[20];

void getc(){
	c[0][0] = 1;
	rep(i, 1, 13) {
		c[i][0] = 1;
		rep(j, 1, i+1) {
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
}

int sign(db x) {return (x > eps) - (x < -eps);}

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	getc();
	scanf("%d%d%d%d%d", &n, &q, &m, &A, &B);
	rep(i, 1, n+1) scanf("%lf", &l[i]);
	sort(l + 1, l + n + 1);
	rep(i, 1, n+1) 
		rep(k, 0, n - i + 1) 
			w[i] += l[i] / m * c[n - i][k] * pow(l[i] / m, k) * pow(1 - l[i] / m, n - i - k) * (l[i] / (k + 2) + A);
	rep(i, 1, q+1) {
		scanf("%lf",&t);
		ans = 0;
		now = 1;
		rep(i, 1, n+1) {
			if (sign(l[i] - t) >= 0) {
				rep(k, 1, n - i + 2) 
					ans += now * c[n - i + 1][k] * pow(t / m, k) * pow(1 - t / m, n - i + 1 - k) * (t / (k + 1) + A);
				now *= pow(1 - t / m, n - i + 1);
				break;
			}
			else ans += now * w[i];
			now *= 1 - l[i] / m;
		}
		ans += now * (t + B);
		printf("%.6f\n", ans);
	}
	return 0;
}

