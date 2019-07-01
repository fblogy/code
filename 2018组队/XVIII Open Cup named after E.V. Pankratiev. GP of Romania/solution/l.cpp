#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
using namespace std;

bool solve(const vector<int>& a, int left, int right, int k) {
    int l = left, r = right;
    while (l < r && (a[l] & (1 << k)) == (a[r] & (1 << k))) {
        l++;
        r--;
    }
    for (int i = l; i <= r; i += 2) {
        if ((a[i] & (1 << k)) != (a[i + 1] & (1 << k))) {
            return false;
        }
    }
    int cnt = 0;
    for (int i = left; i <= right; ++i) {
        cnt += !!(a[i] & (1 << k));
    }
    return (cnt / 2) % 2 == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    assert(1 <= t && t <= 12);

    for (int _t = 1; _t <= t; ++_t) {
        int n;
        cin >> n;
        assert(1 <= n && n <= 100000);

        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum ^= a[i];
            assert(0 <= a[i] && a[i] <= 1000000000);
        }
        if (sum == 0) {
            cout << "Draw\n";
            continue;
        }
        int k = 29;
        while (!(sum & (1 << k))) {
            k--;
        }
        if (n % 2 == 0) {
            cout << "First\n";
        } else if ((a[0] & (1 << k)) == 0 && (a[n - 1] & (1 << k)) == 0) {
            cout << "Second\n";
        } else {
            bool firstWins = false;
            if ((a[0] & (1 << k)) != 0) {
                firstWins |= solve(a, 1, n - 1, k);
            }
            if ((a[n - 1] & (1 << k)) != 0) {
                firstWins |= solve(a, 0, n - 2, k);
            }
            cout << (firstWins ? "First\n": "Second\n");
        }
    }
}
