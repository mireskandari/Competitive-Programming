#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, x;
		cin >> n >> m >> x;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<int> idx(n);
		iota(idx.begin(), idx.end(), 0);
		sort(idx.begin(), idx.end(), [&](int l, int r) {
			return a[l] < a[r];
		});

		vector<int> tower(n);
		vector<int> aux(m);
		for (int i = n - 1; i >= 0; --i) {
			int ii = -(i - n) - 1;
			tower[idx[i]] = ii % m;
			aux[ii % m] += a[idx[i]];
		}
		sort(aux.begin(), aux.end());
		for (int i = 0; i < m; ++i) {
			if (lower_bound(aux.begin(), aux.end(), aux[i] - x) != aux.begin()) {
				goto kir;
			}
		}
		cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			cout << tower[i] + 1 << ' ';
		}
		cout << '\n';
		continue;
kir:
		cout << "NO\n";
	}
}