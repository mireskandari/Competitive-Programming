#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 2e5 + 10, A = 1e6 + 10, SQ = 450;

int n, m, a[N], cnt[A];
long long ans[N];

struct Query {
	int l, r, i;

	bool operator<(const Query &o) const {
		return r < o.r;
	}
};

vector<Query> q[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		q[l / SQ].push_back({l, r, i});
	}
	for (int i = 0; i < N; ++i) {
		if (q[i].empty()) {
			continue;
		}
		
		sort(q[i].begin(), q[i].end());

		memset(cnt, 0, sizeof(cnt));
		long long tmp = 0;
		for (int j = q[i][0].l; j <= q[i][0].r; ++j) {
			tmp -= 1ll * cnt[a[j]] * cnt[a[j]] * a[j];
			cnt[a[j]]++;
			tmp += 1ll * cnt[a[j]] * cnt[a[j]] * a[j];
		}
		ans[q[i][0].i] = tmp;

		int mol = q[i][0].l, mor = q[i][0].r;
		for (int x = 1; x < (int) q[i].size(); ++x) {
			for (int j = min(mol, q[i][x].l); j < max(mol, q[i][x].l); ++j) {
				tmp -= 1ll * cnt[a[j]] * cnt[a[j]] * a[j];
				if (mol > q[i][x].l) {
					cnt[a[j]]++;
				} else {
					cnt[a[j]]--;
				}
				tmp += 1ll * cnt[a[j]] * cnt[a[j]] * a[j];
			}
			mol = q[i][x].l;
			for (++mor; mor <= q[i][x].r; ++mor) {
				tmp -= 1ll * cnt[a[mor]] * cnt[a[mor]] * a[mor];
				cnt[a[mor]]++;
				tmp += 1ll * cnt[a[mor]] * cnt[a[mor]] * a[mor];
			}
			mor--;

			ans[q[i][x].i] = tmp;
		}
	}

	for (int i = 0; i < m; ++i) {
		cout << ans[i] << '\n';
	}
}