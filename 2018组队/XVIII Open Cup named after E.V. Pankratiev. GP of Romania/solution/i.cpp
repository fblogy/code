#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int T; cin >> T;
    while (T--) {
        int N, M, MOD; cin >> N >> M >> MOD;
 
        vector< vector<int> > dp(N, vector<int>(N + 1, 0));
        vector< vector<int> > next(N, vector<int>(N + 1, 0));
        dp[0][N] = 1;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j)
                for (int k = 1; k <= N; ++k)
                    next[j][k] = 0;
 
            for (int j = 0; j < N; ++j)
                for (int k = 1; k <= N; ++k) {
                    if (!dp[j][k])
                        continue;
                    int need = N - k + j;
                    // if we want to decrease the number
                    if (i > need && j + 1 < N) {
                        int most = max(1, k - (i - need));
                        next[j + 1][most] += dp[j][k];
                        if (next[j + 1][most] >= MOD)
                            next[j + 1][most] -= MOD;
                        next[j + 1][k] -= dp[j][k];
                        if (next[j + 1][k] < 0)
                            next[j + 1][k] += MOD;
                    }
 
                    // if we dont want to decrease
                    int most = (N - k + 1) * (N - k) / 2 + N * (N - 1) / 2;
                    if (i < most) {
                        next[j][k] += dp[j][k];
                        if (next[j][k] >= MOD)
                            next[j][k] -= MOD;
                        if (k < N) {
                            next[j][k + 1] -= dp[j][k];
                            if (next[j][k + 1] < 0)
                                next[j][k + 1] += MOD;
                        }
                    }
                }
 
            for (int j = 0; j < N; ++j)
                for (int k = 1; k <= N; ++k) {
                    next[j][k] += next[j][k - 1];
                    if (next[j][k] >= MOD)
                        next[j][k] -= MOD;
                }
 
            swap(next, dp);
            int answer = 0;
            for (int j = 0; j < N; ++j)
                for (int k = 1; k <= N; ++k) {
                    answer += dp[j][k];
                    if (answer >= MOD)
                        answer -= MOD;
                }
 
            cout << answer << " ";
        }
        cout << "\n";
    }
}
