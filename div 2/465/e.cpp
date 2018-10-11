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

const int N=10005;
const int mod=1e9+7;

int n, siz[N], ma[N][105], mi[N][105], tim, x, y, num;
string s;
bool op;

void work(int l, int r, int u) {
	int tmp = 0, pos = -1;
	rep(i, l, r+1) {
		if (s[i] == '(') tmp++;
		else if (s[i] == ')') tmp--;
		if (s[i] == '?' && tmp == 0) {pos = i; break;}
	}
	//if (num == 2) {dd(num),dd(l),dd(r),dd(u);dd(pos);de(tmp);return;}
	//dd(pos);de(tmp);
	//return;
	if (tmp == 0 && pos == -1 && s[l] == '(') { work(l + 1, r - 1, u); return;}
	if (tmp == 0 && pos == -1) {
		rep(i, l, r+1) if (s[i] >= '0' && s[i] <= '9') {
			siz[u] = 0;
			ma[u][0] = s[i] - '0';
			mi[u][0] = s[i] - '0';
			return;
		}
	}
	int v1 = ++tim, v2 = ++tim;
	work(l, pos - 1, v1);
	work(pos + 1, r, v2);
	siz[u] = siz[v1] + siz[v2] + 1;
	rep(i, 0, 100+1) ma[u][i] = -1 << 29, mi[u][i] = 1 << 29;
	rep(i, 0, min(siz[v1], x)+1)
		rep(j, 0, min(siz[v2], x)+1) if (op == 0){
			ma[u][i + j] = max(ma[u][i + j], ma[v1][i] - mi[v2][j]);
			mi[u][i + j] = min(mi[u][i + j], mi[v1][i] - ma[v2][j]);			
			ma[u][i + j + 1] = max(ma[u][i + j + 1], ma[v1][i] + ma[v2][j]);
			mi[u][i + j + 1] = min(mi[u][i + j + 1], mi[v1][i] + mi[v2][j]);
		}else {
			ma[u][i + j + 1] = max(ma[u][i + j + 1], ma[v1][i] - mi[v2][j]);
			mi[u][i + j + 1] = min(mi[u][i + j + 1], mi[v1][i] - ma[v2][j]);			
			ma[u][i + j] = max(ma[u][i + j], ma[v1][i] + ma[v2][j]);
			mi[u][i + j] = min(mi[u][i + j], mi[v1][i] + mi[v2][j]);
		}
}

int main(){
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> x >> y;
	if (x > y) { swap(x, y); op = 1;}
	tim = 1;
	work(0, sz(s) - 1, 1);
	cout << ma[1][x];
	return 0;
}

