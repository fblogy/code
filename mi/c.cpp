#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse2")
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
#define all(a) (a).begin(), (a).end()
#define pw(x) (1ll<<(x))
#define lb(x) ((x) & -(x))
#define endl "\n"
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
int P;
int add(int a, int b) {if((a += b) >= P) a -= P; return a < 0 ? a + P : a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//----

const int N = 50;
ll ans;
int a[N][N], b[N][N], n, t1, t2;

namespace GaussInt{
	static const int N = ::N;
	int a[N][N], x[N]; //增广矩阵和解集
	bool ok[N]; // 标记变元是否确定
	int free[N], free_num; // 一组合法自由变元 
	int add(int a, int b) {if ((a += b) >= P) a -= P; return a < 0 ? a + P : a;}
	int mul(int a, int b) {return 1ll * a * b % P;}
	int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
	int Gauss(int equ, int var){
		int k, col, p;
		fill_n(free, var, 0); free_num = 0;
		fill_n(x, var, 0);
		for(k = col = 0; k < equ && col < var; ++k, ++col){
			p = k; rep(i, k+1, equ) if (a[i][col]) {p = i; break;}
			if (p != k) rep(j, k, var+1) swap(a[p][j], a[k][j]);
			if(!a[k][col]) {return 0;k--; continue;}
			int inv = kpow(a[k][col], P - 2);
			rep(i, col, var+1) a[k][i] = mul(a[k][i], inv);
			rep(i, k+1, equ){
				if(!a[i][col]) continue;
				int t = a[i][col];
				rep(j, col, var+1) a[i][j] = add(a[i][j], -mul(a[k][j], t));
			}
		}
		return 1;
		rep(i, k, equ) if (a[i][var]) return -1;//无解
		if(k < var){
			/*
			int pre = var;
			per(i, 0, k) {
				int num = 0;
				rep(j, 0, var) if (a[i][j]) {
					if (!num) p = j; num++;
				}
				rep(j, 0, i) if (a[j][p]) {
					int t = a[j][p];
					rep(l, p, var+1) a[j][l] = add(a[j][l], -mul(a[i][l], t));
				}
				rep(j, p+1, pre) free[free_num++] = j; pre = p; 
				if(num > 1) continue;
				x[p] = a[i][var];
				ok[p] = 1;
			}*/
			return var - k;//自由变元个数
		}
		per(i, 0, var) {
			int t = a[i][var];
			rep(j, i+1, var) if (a[i][j]) t = add(t, -mul(a[i][j], x[j]));
			x[i] = t;
		}
		return 0;
	}
}


int main() {
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	srand(time(0));
	cin >> n >> P;
	int cnt = 0, cnt2 = 0, cnt3 = 0;
	rep(i, 1, n+1) rep(j, 1, n+1) cin >> b[i][j];
	rep(i, 1, n+1)
		rep(j, 1, n+1) {
			rep(l, 1, n) {
				if (max(i, j) + l - 1 > n) break;
				rep(ii, i, i+l)
					rep(jj, j, j+l) {
						GaussInt :: a[ii - i][jj - j] = b[ii][jj];
					}
				cnt++;
				cnt3 += pow(l, 3);
				if (!GaussInt :: Gauss(l, l)) continue;
				t1 = 0; 
				rep(ii, 1, n+1) {
					if (ii >= i && ii <= i + l - 1) continue;
					t2 = 0;//t1++;
					rep(jj, 1, n+1) {
						if (jj >= j && jj <= j + l - 1) continue;
						GaussInt :: a[t1][t2++] = b[ii][jj];
					}
					t1++;
				}
				//ans++;
				cnt2 += pow(n - l, 3);
				if (GaussInt :: Gauss(n - l, n - l)) ans++;
				//if (det(n - l + 1)) ans++;
			}
		}
	cout << ans << endl;
	//de(cnt);
	//de(cnt2);
	//de(cnt3);
	return 0;
}


