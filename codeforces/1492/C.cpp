#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;

	vector<int> en(m), bg(m);
	for (int i = 0, j = 0; i < m; ++i) {
		while (j < n && s[j] != t[i]) {
			++j;
		}
		bg[i] = j++;
	}
	for (int i = m - 1, j = n - 1; i >= 0; --i) {
		while (j >= 0 && s[j] != t[i]) {
			--j;
		}
		en[i] = j--;
	}
	
	int ans = 0;
	for (int i = 0; i < m - 1; ++i) {
		ans = max(ans, en[i + 1] - bg[i]);
	}

	cout << ans;
}

