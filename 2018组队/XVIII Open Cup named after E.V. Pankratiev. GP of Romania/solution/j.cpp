#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
const int MOD = 1e9 + 7;
 
vector<VI> Comb;
 
void dfs(int node, int f, vector<vector<PII>> &G, VI &sum, VI &up) {
    for(auto v : G[node]) {
        int nxt = v.first;
        int cost = v.second;
        if(nxt == f)
            continue;
        up[nxt] = cost;
        dfs(nxt, node, G, sum, up);
        sum[node] += sum[nxt];
    }
    ++sum[node];
}   
 
void dfsConf(int node, int f, vector<vector<PII>> &G, VI &val, VI &sum, int &ans, int m) {
    for(auto v : G[node]) {
        int nxt = v.first;
        int cost = v.second;
        if(nxt == f)
            continue;
        dfsConf(nxt, node, G, val, sum, ans, m);
        ans += cost * min(sum[nxt], 2 * m - sum[nxt]);
        sum[node] += sum[nxt];
    }
    sum[node] += val[node];
}
 
int solveConf(int n, int m, vector<vector<PII>> &G, VI &conf) {
    vector<int> sum(n, 0), val(n, 0);
    for(int i = 0; i < 2 * m; ++i)
        val[conf[i]]++;
    int ans = 0;
    dfsConf(0, -1, G, val, sum, ans, m);
    return ans;
}
 
void back(int poz, int n, int m, VI &conf, vector<vector<PII>> &G, int &ans) {
    if(poz == 2 * m) {
        ans += solveConf(n, m, G, conf);
        ans %= MOD;
        return;
    }
 
    for(int i = 0; i < n; ++i) {
        conf[poz] = i;
        back(poz + 1, n, m, conf, G, ans);
    }
}
 
int solveExponential(int n, int m, vector<vector<PII>> &G) {
    int ans = 0;
    VI conf(2 * m, 0);
    back(0, n, m, conf, G, ans);
    return ans;
}
 
int solveCubic(int n, int m, vector<vector<PII>> &G) {
    vector<int> sum(n, 0), up(n, 0);
    dfs(0, -1, G, sum, up);
     
    int ans = 0;
 
    for(int node = 1; node < n; ++node) {
        int totalCoef = 0;
        VI powLeft(m + 1, 1), powRight(m + 1, 1);
 
        for(int i = 1; i <= m; ++i) {
            powLeft[i] = 1LL * powLeft[i - 1] * sum[node] % MOD;
            powRight[i] = 1LL * powRight[i - 1] * (n - sum[node]) % MOD;
        }
 
        for(int taxiLeft = 0; taxiLeft <= m; ++taxiLeft) {
            for(int clientLeft = 0; clientLeft <= m; ++clientLeft) {
                int taxiRight = m - taxiLeft;
                int clientRight = m - clientLeft;
                 
                int passes = min(taxiLeft, clientRight) + min(taxiRight, clientLeft);
                assert(passes == min(taxiLeft + clientLeft, taxiRight + clientRight));
 
                int coef = 1LL * Comb[m][taxiLeft] * Comb[m][clientLeft] % MOD;
                coef = 1LL * (1LL * powLeft[taxiLeft] * powLeft[clientLeft] % MOD) * coef % MOD;
                coef = 1LL * (1LL * powRight[taxiRight] * powRight[clientRight] % MOD) * coef % MOD;
                coef = 1LL * coef * passes % MOD;
                totalCoef += coef;
                totalCoef %= MOD;
            }
        }
 
        ans += 1LL * totalCoef * up[node] % MOD;
        ans %= MOD;
    }
 
    return ans;
}
 
int solveQuadratic(int n, int m, vector<vector<PII>> G) {
     
    int ans = 0;
    vector<int> sum(n, 0), up(n, 0);
    dfs(0, -1, G, sum, up);
 
    for(int node = 1; node < n; ++node) {
        int powerLeft = 1;
        VI powerRight(2 * m + 1, 1);
        for(int i = 1; i <= 2 * m; ++i)
            powerRight[i] = 1LL * powerRight[i - 1] * (n - sum[node]) % MOD;
         
        int coef = 0;
        for(int left = 0; left <= 2 * m; ++left) {
            coef += 1LL * (1LL * (1LL * Comb[2 * m][left] * powerLeft % MOD) * powerRight[2 * m - left] % MOD) * min(left, 2 * m - left) % MOD;
            coef %= MOD;
            powerLeft = 1LL * powerLeft * sum[node] % MOD;
        }
         
        ans += 1LL * coef * up[node] % MOD;
        ans %= MOD;
    }
 
    return ans;
}
 
int main(int argc, char *argv[]) {
    int n, m; cin >> n >> m;
     
    vector<vector<PII>> G(n, vector<PII>());
 
    for(int i = 0; i < n - 1; ++i) {
        int a, b, cost; cin >> a >> b >> cost;
        a--, b--;
        G[a].pb({b, cost});
        G[b].pb({a, cost});
    }
 
    Comb = vector<VI> (2 * m + 1, vector<int> (2 * m + 1, 0));
     
    for(int i = 0; i <= 2 * m; ++i) {
        Comb[i][0] = 1;
        for(int j = 1; j <= i; ++j)
            Comb[i][j] = (Comb[i - 1][j] + Comb[i - 1][j - 1]) % MOD;
    }
      
    cout << solveQuadratic(n, m, G) << "\n";
}
