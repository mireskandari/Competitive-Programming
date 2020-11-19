#include <bits/stdc++.h>
using namespace std;

template <typename T>
int len(const T& a) {
	return a.size();
}
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto& i : a) cin >> i;
		long long sum = accumulate(a.begin(), a.end(), 0ll);
		cout << max(1ll * (n - 1) * (*max_element(a.begin(), a.end())) - sum, ((-sum) % (n - 1) + n - 1) % (n - 1)) << '\n';
	}
	return 0;
}

