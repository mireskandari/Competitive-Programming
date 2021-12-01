#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int MOD = 998244353;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

constexpr int N = 5e5 + 10;

int open[N], ended[N], n, a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			++a[i];
		}
		for (int i = 0; i <= n + 5; ++i) {
			open[i] = 0;
			ended[i] = 0;
		}
		open[0] = 1;
		for (int i = 0; i < n; ++i) {
			add(open[a[i]], open[a[i]]);
			add(open[a[i]], open[a[i] - 1]);
			add(ended[a[i]], ended[a[i]]);
			if (a[i] >= 2) {
				add(ended[a[i]], open[a[i] - 2]);
			}
			add(ended[a[i] + 2], ended[a[i] + 2]);
		}
		int sum = 0;
		for (int i = 1; i <= n + 1; ++i) {
			add(sum, open[i]);
			add(sum, ended[i]);
			//cerr << ended[i] << '\n';
		}
		cout << sum << '\n';
	}
}