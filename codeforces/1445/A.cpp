#include <bits/stdc++.h>
using namespace std;

template <typename T>
int len(const T& a) {
	return a.size();
}
using ll = long long;

const int N = 100;

int a[N], b[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, x;
		cin >> n >> x;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < n; ++i)
			cin >> b[i];
		bool ok = true;
		for (int i = 0, j = n - 1; i < n; ++i, --j) {
			if (a[i] + b[j] > x) {
				ok = false;
				break;
			}
		}
		if (ok)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}

