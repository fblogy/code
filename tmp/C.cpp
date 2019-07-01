
 #include <bits/stdc++.h>
using namespace std;

long long forests[5][55];

int main() {
    freopen("chemistry.in", "r", stdin);
    freopen("chemistry.out", "w", stdout);

    int n; cin >> n;
    for (int i = 0; i <= 4; i++) forests[i][0] = 1;
    for (int i = 1; i <= n / 2; i++) {
        vector<long long> temp((n - 1) / i + 1);
        for (int j = 0; j <= (n - 1) / i && j <= 4; j++) {
            if (j == 0) temp[j] = 1;
            else {
                long long g = __gcd(temp[j - 1], (long long)j);
                long long a = temp[j - 1] / g, b = j / g;
                temp[j] = a * ((forests[3][i - 1] + j - 1) / b);
            }
        }
        for (int j = n - i; j >= 0; j--) {
            for (int l = 3; l >= 0; l--) {
                for (int k = 1; k <= (n - j) / i && k <= 4 - l; k++) forests[k + l][j + k * i] += forests[l][j] * temp[k];
            }
        }
    }
    long long ans = forests[4][n - 1];
    if (n % 2 == 0) ans -= forests[3][n / 2 - 1] * (forests[3][n / 2 - 1] - 1) / 2;
    cout << ans << endl;
    return 0;
}
