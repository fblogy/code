#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cassert>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    const int INF = 0x3f3f3f3f;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    deque<pair<int, int>> d;
    for (int j = 0; j < m; ++j) {
        dist[n - 1][j] = 0;
        d.push_back(make_pair(n - 1, j));
    }
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    while (!d.empty()) {
        int x = d.front().first;
        int y = d.front().second;
        d.pop_front();

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (A[x][y] == '#' && A[nx][ny] == '#') {
                if (dist[nx][ny] > dist[x][y]) {
                    dist[nx][ny] = dist[x][y];
                    d.push_front(make_pair(nx, ny));
                }
            } else if (k == 3 && A[x][y] == '#') {
                if (dist[nx][ny] > dist[x][y]) {
                    dist[nx][ny] = dist[x][y];
                    d.push_front(make_pair(nx, ny));
                }
            } else if (k == 3 && dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                d.push_back(make_pair(nx, ny));
            }
        }
    }

    vector<string> B(n, string(m, '.'));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (A[i][j] == '#') {
                B[i + dist[i][j]][j] = '#';
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << B[i] << '\n';
    }

}
