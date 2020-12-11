#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T& a) { return a.size(); }

constexpr int mxn = 1e5 + 10;

int n, q, a[mxn], qs[mxn];
long long pref[mxn];
set<long long> bitches;

void workbitch(int b, int e) {
	bitches.insert(pref[e - 1] - (b == 0 ? 0 : pref[b - 1]));
	if (b == e - 1) {
		return;
	}
	int mid = (a[e - 1] + a[b]) / 2;
	int pos = upper_bound(a, a + n, mid) - a;
	if (pos == e) {
		return;
	}
	workbitch(b, pos);
	workbitch(pos, e);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		bitches.clear();
		cin >> n >> q;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a, a + n);
		pref[0] = a[0];
		for (int i = 1; i < n; ++i) {
			pref[i] = pref[i - 1] + a[i];
		}
		for (int i = 0; i < q; ++i) {
			cin >> qs[i];
		}
		workbitch(0, n);
		for (int i = 0; i < q; ++i) {
			if (bitches.count(qs[i]) == 1) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	}
	return 0;
}

