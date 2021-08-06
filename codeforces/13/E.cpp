#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

constexpr int N = 1e5 + 10, SQ = 350;

int n, m;
int a[N], dp[N], cnt[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		dp[i] = i;
		int num = i / SQ;
		int lm = min(n, (num + 1) * SQ);
		while (dp[i] + a[dp[i]] < lm) {
			dp[i] += a[dp[i]];
			++cnt[i];
		}
	}

	while (m--) {
		int op;
		cin >> op;
		if (op == 0) {
			int i, x;
			cin >> i >> x;
			--i;
			a[i] = x;
			int num = i / SQ;
			int lm = min(n, (num + 1) * SQ);
			for (int j = lm - 1; j >= num * SQ; --j) {
				dp[j] = j;
				cnt[j] = 0;
				if (j + a[j] < lm) {
					dp[j] = dp[j + a[j]];
					cnt[j] = cnt[j + a[j]] + 1;
				}
			}
		} else {
			int i;
			cin >> i;
			--i;
			int sum = 0;
			//cerr << i << '\n';
			while (true) {
				sum += cnt[i];
				i = dp[i];
				//cerr << i << '\n';
				if (i + a[i] >= n) {
					break;
				}
				i += a[i];
				//cerr << i << '\n';
				sum++;
			}
			//cerr << '\n';
			cout << i + 1 << ' ' << sum + 1 << '\n';
		}
	}
			
}

