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

const int N = 3e3 + 7;
const int M = 1e5 + 7;
const int mod = 1e9+7;


int head[N], val[N], ecnt;
int to[M], ne[M], weight[M];
bool vis[N];
int fa[N], link[N];
int n, m;

void init() {
    memset(head + 1, -1, sizeof(int) * n);
    memset(link + 1, -1, sizeof(int) * n);
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
    ecnt = 0;
}

void add_edge(int u, int v, int w) {
    to[ecnt] = v; weight[ecnt] = w; ne[ecnt] = head[u]; head[u] = ecnt++;
    to[ecnt] = u; weight[ecnt] = w; ne[ecnt] = head[v]; head[v] = ecnt++;
}

int findset(int u) { // 并查集
    return u == fa[u] ? u : fa[u] = findset(fa[u]);
}

void merge(int u, int v) {
    int p = u;
    while (~link[p]) p = link[p];
    link[p] = v;
    fa[v] = u;
}

int MinimumCutPhase(int cnt, int &s, int &t) {
    memset(val + 1, 0, sizeof(int) * n);
    memset(vis + 1, 0, sizeof(bool) * n);
    std::priority_queue<std::pair<int, int>> que;
    t = 1;
    while (--cnt) {
        vis[s = t] = true;
        for (int u = s; ~u; u = link[u]) {
            for (int p = head[u]; ~p; p = ne[p]) {
                int v = findset(to[p]);
                if (!vis[v])
                    que.push(std::make_pair(val[v] += weight[p], v));
            }
        }
        t = 0;
        while (!t) {
            if (que.empty()) return 0; // 图不连通
            auto pa = que.top(); que.pop();
            if (val[pa.second] == pa.first)
                t = pa.second;
        }
    }
    return val[t];
}

int StoerWagner() {
    int res = pw(30);
    for (int i = n, s, t; i > 1; --i) {
        res = min(res, MinimumCutPhase(i, s, t));
        if (res == 0) break;
        merge(s, t);
    }
    return res;
}

int main() {
	freopen("a.in","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cout << setiosflags(ios::fixed);
	//cout << setprecision(2);
    while (scanf("%d%d", &n, &m) != EOF) {
        init();
        for (int i = 0, u, v, w; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
        }
        printf("%d\n", StoerWagner());
    }
}
