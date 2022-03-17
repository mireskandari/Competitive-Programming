#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1 << 18;

int n, a[N], cnt[N];
bool cool[N], mark[N];
int par[N];

int root(int v) {
	return par[v] == -1 ? v : (par[v] = root(par[v]));
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	memset(par, -1, sizeof(par));

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	cnt[0]++;
	
	long long ans = 0;

	for (int mask = N - 1; mask >= 0; --mask) {
		for (int q = mask; ; q = (q - 1) & mask) {
			int v = mask ^ q, u = q;
			if (cnt[v] && cnt[u]) {
				v = root(v), u = root(u);
				if (v != u) {
					int e = 1;
					if (!mark[v]) {
						e += cnt[v] - 1;
					}
					if (!mark[u]) {
						e += cnt[u] - 1;
					}
					mark[u] = mark[v] = true;
					par[u] = v;
					ans += 1ll * e * mask;
				}
			}
			if (q == 0) {
				break;
			}
		}
	}

	cout << ans - accumulate(a, a + n, 0ll);
}