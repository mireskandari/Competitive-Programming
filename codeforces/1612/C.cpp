#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

long long s(long long n) {
	return n * (n + 1) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		long long k, x;
		cin >> k >> x;
		if (k == 1) {
			cout << 1 << '\n';
			continue;
		}
		if (s(k) >= x) {
			long long low = 1, high = k;
			while (high - low > 0) {
				long long mid = low + (high - low) / 2;
				if (s(mid) >= x) {
					high = mid;
				} else {
					low = mid + 1;
				}
			}
			cout << low << '\n';
		} else {
			long long low = 1, high = k - 1, tmp = s(k) + s(k - 1);
			while (high - low > 0) {
				long long mid = low + (high - low) / 2;
				if (tmp - s(k - 1 - mid) >= x) {
					high = mid;
				} else {
					low = mid + 1;
				}
			}
			cout << k + low << '\n';
		}
	}
}