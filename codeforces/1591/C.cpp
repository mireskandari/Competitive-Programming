#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		vector<int> x(n);
		for (int i = 0; i < n; ++i) {
			cin >> x[i];
		}
		sort(x.begin(), x.end());
		vector<int> neg;
		vector<int> pos;
		for (int i = 0; i < n; ++i) {
			if (x[i] < 0) {
				neg.push_back(x[i]);
			} else {
				pos.push_back(x[i]);
			}
		}
		vector<int> mx;
		int mx_all = 0;
		for (int i = (int) pos.size() - 1, j = 0; i >= 0; --i, ++j) {
			if (j % k == 0) {
				mx.push_back(pos[i]);
			} else {
				mx.back() = max(mx.back(), pos[i]);
			}
			mx_all = max(mx_all, mx.back());
		}
		for (int i = 0, j = 0; i < (int) neg.size(); ++i, ++j) {
			if (j % k == 0) {
				mx.push_back(abs(neg[i]));
			} else {
				mx.back() = max(mx.back(), abs(neg[i]));
			}
			mx_all = max(mx_all, mx.back());
		}
		long long ans = 0;
		for (auto &v : mx) {
			ans += 2ll * v;
		}
		ans -= mx_all;
		cout << ans << '\n';
	}
}