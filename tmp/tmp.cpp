#include <cstdio>
#include <vector>
using namespace std;

int n, k, i, l, x, j, ans[1100000], pu[1100000], n1[1100], ss[1100];
bool used[1100];
vector <int> ve[1100];

struct B {
	int s[40];
	void operator |= (int x) {
		s[x / 30] |= (1 << (x % 30));
	}
} He[1100];

bool operator & (B &x, B &y) {
	for (int i = 0; i <= n / 30; i++)	if (x.s[i] & y.s[i])	return true;
	return false;
}

void bfs(int x) {
	int q, h, i;
	for (i = 1; i <= n; i++)	used[i] = false;
	for (n1[q = h = 1] = x, used[n1[q]] = true; q <= h; q++)
		for (i = 0; i < (int) ve[n1[q]].size(); i++)
			if (!used[ve[n1[q]][i]]) {
				n1[++h] = ve[n1[q]][i];
				used[ve[n1[q]][i]] = true;
			}
	for (i = 1; i <= n; i++)	if (used[i])	ss[i]++;
}

void Bfs(int x) {
	int q, h, i;
	for (i = 1; i <= n; i++)	used[i] = false;
	for (h = 0, i = 1; i <= n; i++)	if (i > k && i != x)	n1[++h] = i, used[i] = true;
	for (q = 1; q <= h; q++)
		for (i = 0; i < (int) ve[n1[q]].size(); i++)
			if (!used[ve[n1[q]][i]] && ve[n1[q]][i] != x) {
				n1[++h] = ve[n1[q]][i];
				used[ve[n1[q]][i]] = true;
			}
	for (i = 1; i <= n; i++)	if (!used[i])	He[i] |= x;
}

int main() {
	freopen("hospital.in", "r", stdin);
	freopen("hospital.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (i = 1; i <= k; i++) {
		scanf("%d", &l);
		while (l--) {
			scanf("%d", &x);
			ve[x].push_back(i);
		}
	}
	for (i = k + 1; i <= n; i++)	bfs(i);
	for (i = 1; i <= k; i++)	if (!ss[i])	ans[++ans[0]] = i;
	printf("%d\n", ans[0]);
	for (i = 1; i <= ans[0]; i++)	printf("%d ", ans[i]);
	printf("\n");
	ans[0] = 0;
	for (i = 1; i <= n; i++) Bfs(i);

	for (i = 1; i <= n; i++)
		if (ss[i])
			for (j = i + 1; j <= n; j++)
				if (ss[j] && (He[i] & He[j]))	ans[++ans[0]] = i, pu[ans[0]] = j;
	printf("%d\n", ans[0]);
	if (ans[0] <= 10000)	for (i = 1; i <= ans[0]; i++)	printf("%d %d\n", ans[i], pu[i]);
}
