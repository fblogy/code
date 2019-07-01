#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>
 
using namespace std;
 
static const int kModulo = 1000 * 1000 * 1000 + 7;
 
int64_t cntSteps = 0;
class Solver {
  public:
    Solver(vector< vector<int> > mat):
        m_mat(mat),
        N(mat.size()),
        M(mat[0].size()),
        m_pos(N, vector< vector<int> >(N + M)),
        haveSolution(false) {
    }
 
    pair<bool, int> solve(int K) {
        vector<int> values; values.reserve(N * M);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                values.push_back(m_mat[i][j]);
 
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                m_mat[i][j] = lower_bound(values.begin(), values.end(), m_mat[i][j]) - values.begin();
 
        // now we know values are from 0 to N + M - 1
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                m_pos[i][m_mat[i][j]].push_back(j);
 
        vector<int> fixed(M, -1), bad(N, 0), fixedLine(N, -1);
        int res = solve(0, K, fixed, bad, fixedLine);
        return make_pair(haveSolution, res);
    }
 
  private:
    bool fixCol(vector<int>& fixedLine, int col, int start, int val) {
        for (int i = start; i < N; ++i) {
            if (val != m_mat[i][col]) {
                if (fixedLine[i] == -1) {
                    fixedLine[i] = m_mat[i][col];
                } else if (fixedLine[i] != m_mat[i][col]) {
                    return false;
                }
            }
        }
        return true;
    }
    int solve(int line, int K, vector<int> &fixed, vector<int> &bad,
           vector<int>& fixedLine, bool allFixed = false) {
        if (line == N) {
            int aux = 1;
            for (int i = 0; i < N; ++i)
                aux = 1LL * aux * (K - bad[i]) % kModulo;
            for (int i = 0; i < M; ++i)
                if (fixed[i] == -1)
                    aux = 1LL * aux * K % kModulo;
            haveSolution = true;
            return aux;
        }
 
        bool not_fixed = false;
        int must = fixedLine[line];
        if (!allFixed) {
            for (int i = 0; i < M; ++i)
                if (fixed[i] == -1) {
                    not_fixed = true; // we have one not fixed value, good to know
                }
        }
        if (allFixed || !not_fixed) { // all is fixed
            bad[line] = must == -1 ? 0: K - 1;
            cntSteps++;
            return solve(line + 1, K, fixed, bad, fixedLine, true);
        }
        if (must != -1) { // ah well, line is forced anyway
            bad[line] = K - 1; // we only have one way
            vector<int> new_fixed(fixed);
            vector<int> newFixedLine = fixedLine;
            for (int i = 0; i < M; ++i)
                if (fixed[i] == -1 && m_mat[line][i] != must) {
                    new_fixed[i] = m_mat[line][i];
                    if (!fixCol(newFixedLine, i, line + 1, m_mat[line][i])) {
                        return 0;
                    }
                }
            return solve(line + 1, K, new_fixed, bad, newFixedLine, allFixed);
        }
 
        int badCurrent = 0;
        vector<int> new_fixed(fixed);
        int answer = 0;
        for (int val = 0; val < N + M; ++val) {
            bool atLeastOne = false;
            for (auto &col : m_pos[line][val])
                if (fixed[col] == -1)
                    atLeastOne = true;
            if (!atLeastOne)
                continue;
            ++badCurrent;
            vector<int> newFixedLine = fixedLine;
            bool doesntWork = false;
            for (int i = 0; i < M; ++i)
                if (fixed[i] == -1) {
                    if (m_mat[line][i] == val)
                        new_fixed[i] = -1;
                    else {
                        new_fixed[i] = m_mat[line][i];
                        if (!fixCol(newFixedLine, i, line + 1, m_mat[line][i])) {
                            doesntWork = true;
                            break;
                        }
                    }
                }
            if (doesntWork) {
                continue;
            }
            bad[line] = K - 1;
            answer = (answer + solve(line + 1, K, new_fixed, bad, newFixedLine)) % kModulo;
        }
        bad[line] = badCurrent;
        // well to be fair, we fixed everything now, problem is pretty much solved
        vector<int> newFixedLine = fixedLine;
        for (int i = 0; i < M; ++i) {
            if (fixed[i] == -1) {
                fixed[i] = m_mat[line][i];
                if (!fixCol(newFixedLine, i, line + 1, m_mat[line][i])) {
                    return answer;
                }
            }
        }
        return (answer + solve(line + 1, K, fixed, bad, newFixedLine, true)) % kModulo;
    }
 
    vector< vector<int> > m_mat;
    int N, M;
    vector< vector< vector<int> > > m_pos;
    bool haveSolution;
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K; assert(cin >> N >> M >> K);
    assert(1 <= N && N <= 300);
    assert(1 <= M && M <= 300);
    assert(1 <= K && K <= N * M);
    vector< vector<int> > C(N, vector<int>(M, 0));
    vector<int> values;
    values.reserve(N * M);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            assert(cin >> C[i][j]);
            assert(1 <= C[i][j] && C[i][j] <= K);
            values.push_back(C[i][j]);
        }
    vector<int> fixed(M, -1);
    vector<int> cant(N, 0);
 
    Solver S(C);
 
    cout << S.solve(K).second << "\n";
}
