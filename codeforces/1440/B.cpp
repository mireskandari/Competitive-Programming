#include <bits/stdc++.h>
using namespace std;

template <typename T>
int len(const T& a) {
	return a.size();
}
using ll = long long;

constexpr int N = 3e5 + 10;

int a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n * k; ++i) {
			cin >> a[i];
		}
		int after = n - ((n - 1) / 2) - 1;
		int now = 0;
		long long sum = 0;
		int cnt = 0;
		for (int i = n * k - 1; i >= 0; --i) {
			if (now < after) {
				now++;
			} else {
				now = 0;
				sum += a[i];
				cnt++;
			}
			if (cnt == k)
				break;
		}
		cout << sum << '\n';
	}
	return 0;
}

