#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(c) cout << #c << " = " << c << endl
#define dd(c) cout << #c << " = " << c << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2020;

namespace Gause {
	static const int N = ::N;
	int equ, var;
	bitset<N> a[N];
	int x[N];
	int free_x[N];
	int free_num;
	int l[N];
	void ini(int n) {
		rep(i, 0, n) x[i] = 0;
		rep(i, 0, n) a[i].reset();
	}
	int Gauss() {
		int max_r, col, k;
		free_num = 0;
		for(k = 0, col = 0; k < equ && col < var; k++, col++) {
			max_r = k;
			for(int i = k + 1; i < equ; i++) {
				if(abs(a[i][col]) > abs(a[max_r][col])) 
					max_r = i;
			}
			if(a[max_r][col] == 0) {
				k--;
				free_x[free_num++] = col;
				continue;
			}
			l[k] = col;
			if(max_r != k) {
				swap(a[k], a[max_r]);
			}
			for(int i = k + 1; i < equ; i++) {
				if(a[i][col] != 0) a[i] ^= a[k];
			}
		}
		for(int i = k; i < equ; i++) {
			if(a[i][col] != 0) return -1;
		}
		for(int i = k - 1; i >= 0; i--) {
			int t = l[i];
			x[t] = a[i][var];
			for(int j = t + 1; j < var; j++) x[t] ^= (a[i][j] & x[j]);
		}
		return 0;
	}
}

int T, n, m, u, v;
bool du[N], vis[N][N];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n >> m;
		Gause :: ini(n);
		rep(i, 1, n+1) rep(j, 1, n+1) vis[i][j] = 0;
		rep(i, 1, n+1) du[i] = 0;
		rep(i, 1, m+1) {
			cin >> u >> v;
			du[u] ^= 1;
			du[v] ^= 1;
			vis[u][v] = vis[v][u] = 1;
		}
		Gause :: equ = Gause :: var = n;
		rep(i, 1, n+1) {
			vis[i][i] = du[i];
			rep(j, 1, n+1) Gause :: a[i-1][j-1] = vis[i][j];
			Gause :: a[i-1][n] = du[i];	
		}
		Gause::Gauss();
		bool Vis[2] = {0};
		rep(i, 1, n + 1) Vis[Gause::x[i - 1]] = 1;
		if(Vis[0] && Vis[1]) {
			cout << 2 << endl;
		} else {
			cout << 1 << endl;
			if(Vis[1]) rep(i, 1, n + 1) Gause::x[i - 1] = 0;
		}
		rep(i, 1, n + 1) cout << Gause::x[i - 1] + 1 << " ";cout << endl;
	}
	return 0;
}
