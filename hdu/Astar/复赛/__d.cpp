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

int ma, x, y, o, k, ans, T;
vector<int> pos[N][4];
int l1, r1, n, R, nn, p;

struct node2 {
	int i, x, sum;
	bool operator < (const node2 & b) const{
		return i < b.i && x < b.x;
	}
} a2[N];

struct node3 {
	int i, x, y, sum;
	bool operator < (const node3 & b) const{
		return i < b.i && x < b.x && y < b.y;
	}
} a3[N];

struct node4 {
	int i, x, y, z, sum;
	bool operator < (const node4 & b) const{
		return i < b.i && x < b.x && y < b.y && z < b.z;
	}
} a4[N];


struct node5 {
	int i, x, y, z, w, sum;
	bool operator < (const node5 & b) const{
		return i < b.i && x < b.x && y < b.y && z < b.z && w < b.w;
	}
} a5[N];

int Add(int x, int y) {
	return (x + y) % mod;
}


int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> T;
	rep(cas, 0, T) {
		cin >> k >> n; nn = 0;
		ans = 0;
		rep(t, 0, k-1) {
			rep(i, 1, n+1) pos[i][t].clear();
			rep(i, 1, n+1) cin >> x, pos[x][t].pb(i);
		}		
		rep(i, 1, n+1) {
			cin >> x;
			if (k == 2) {
				rep(j, 0, sz(pos[x][0]))  
					a2[++nn] = {i, pos[x][0][j], 1};
			}
			if (k == 3) {
				rep(j, 0, sz(pos[x][0]))  
					rep(k, 0, sz(pos[x][1]))
						a3[++nn] = {i, pos[x][0][j], pos[x][1][k], 1};
			}
			if (k == 4) {
				rep(j, 0, sz(pos[x][0]))  
					rep(k, 0, sz(pos[x][1]))
						rep(l, 0, sz(pos[x][2])) 
							a4[++nn] = {i, pos[x][0][j], pos[x][1][k], pos[x][2][l], 1};
			}
			if (k == 5) {
				rep(j, 0, sz(pos[x][0]))  
					rep(k, 0, sz(pos[x][1]))
						rep(l, 0, sz(pos[x][2]))
							rep(m, 0, sz(pos[x][3])) 
								a5[++nn] = {i, pos[x][0][j], pos[x][1][k], pos[x][2][l], pos[x][3][m], 1};
			}
		}
		n = nn;
		rep(i, 1, n+1) {
			rep(j, 1, i) {
				if (k == 2) {
					if (a2[j] < a2[i]) a2[i].sum = Add(a2[i].sum, a2[j].sum);
				}
				if (k == 3) {
					if (a3[j] < a3[i]) a3[i].sum = Add(a3[i].sum, a3[j].sum);
				}
				if (k == 4) {
					if (a4[j] < a4[i]) a4[i].sum = Add(a4[i].sum, a4[j].sum);
				}
				if (k == 5) {
					if (a5[j] < a5[i]) a5[i].sum = Add(a5[i].sum, a5[j].sum);
				}
			}
		} 
		rep(i, 1, n+1) {
			if (k == 2) ans = Add(ans, a2[i].sum);
			if (k == 3) ans = Add(ans, a3[i].sum);
			if (k == 4) ans = Add(ans, a4[i].sum);
			if (k == 5) ans = Add(ans, a5[i].sum);
		}
		cout << ans << endl;
	}
	return 0;
}

