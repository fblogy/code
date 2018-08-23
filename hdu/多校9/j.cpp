#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

int n1, n2,T, sw, mi, a[10], b[10];

pii A2, B2, A1, B1;

int solve() {
	if (A1 != B1) return A1 < B1 ? 1 : -1;
	if (A2 != B2) return A2 < B2 ? 1 : -1;
	return 0;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> T;
    rep(cas, 0, T) {
        cin >> n1 >> n2;
        rep(i, 1, 4) a[i] = b[i] = 1 << 30;
        rep(i, 1, n1+1) cin >> a[i];
        rep(i, 1, n2+1) cin >> b[i];
		A1 = mp(a[1]+2, 1 << 30);
		if (a[2] + 1 < a[3]) A2 = mp(a[2]+1, a[3]);
		else A2 = mp(a[3], a[2]+1);
		B1 = mp(b[1]+2, 1 << 30);
		if (b[2] + 1 < b[3]) B2 = mp(b[2]+1, b[3]);
		else B2 = mp(b[3], b[2]+1);
		if (A1 > A2) swap(A1, A2);
		if (B1 > B2) swap(B1, B2);
        int ans = solve();
        cout << ans << endl;
    }
    return 0;
}
