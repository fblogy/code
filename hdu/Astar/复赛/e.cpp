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

const int N = 25;
const int mod = 1e9+7;

struct node{
	int x, y, s;
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int T, n, m, k, a[N][N], ans, xx, yy, cnt, d[N][N][pw(7)], val[N * N], s;


int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
	cin >> T;
	srand(time(0));
	rep(cas, 0, T) {
		cin >> n >> m >> k;
		rep(i, 0, n)
			rep(j, 0, m) cin >> a[i][j];
		ans = pw(30);
		rep(cnt, 0, 500) {
			queue<node> q;
			memset(d, 10, sizeof(d));
			memset(val, -1, sizeof(val));
			rep(i, 0, n)
				rep(j, 0, m) {	
					if (a[i][j] > 0) {
						if (!~val[a[i][j]]) 
							val[a[i][j]] = rand() % k;
						d[i][j][pw(val[a[i][j]])] = 0; 
						q.push(node{i, j, (int)pw(val[a[i][j]])});
					}
				}
			/*rep(i, 0, n) {
				rep(j, 0, n) cout << val[a[i][j]] << " ";
				cout << endl;
			}*/
			while (!q.empty()) {
				node tmp = q.front(); q.pop();
				if (tmp.s == pw(k) - 1) {
					ans = min(ans, d[tmp.x][tmp.y][tmp.s]);
					break;
				}
				rep(i, 0, 4) {
					xx = tmp.x + dx[i];
					yy = tmp.y + dy[i];
					if (xx >= n || xx <0 || yy >= m || yy < 0 || a[xx][yy] == -1) continue;
					s = tmp.s;
					if (a[xx][yy] > 0) s |= pw(val[a[xx][yy]]);
					if (d[xx][yy][s] > d[tmp.x][tmp.y][tmp.s] + 1) {
						d[xx][yy][s] = d[tmp.x][tmp.y][tmp.s] + 1;
						q.push(node{xx, yy, s}); 
					}
				}
			}
		}
		if (ans < 1000) cout << ans << endl;
		else cout << -1 << endl;
	}
	return 0;
}

