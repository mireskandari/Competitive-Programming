#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> ll(n + 1, 1), lr(n + 1, 1);
		for (int i = 1; i <= n; ++i) {
			if (s[i - 1] == 'L') {
				ll[i] = lr[i - 1] + 1;
			} else {
				lr[i] = ll[i - 1] + 1;
			}
		}
		vector<int> rl(n + 1, 1), rr(n + 1, 1);
		for (int i = n - 1; i >= 0; --i) {
			if (s[i] == 'L') {
				rl[i] = rr[i + 1] + 1;
			} else {
				rr[i] = rl[i + 1] + 1;
			}
		}
		for (int i = 0; i <= n; ++i) {
			cout << rr[i] + ll[i] - 1 << ' ';
		}
		cout << '\n';
	}

}

