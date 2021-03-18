#include <bits/stdc++.h>
using namespace std;
#define int long long 
template <typename T> inline int len(const T &a) { return a.size(); }


int my_gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = my_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	long long k;
	cin >> k;
	
	const int maxc = 2 * max(n, m);

	vector<int> a(n), b(m);
	vector<int> p1(maxc, -1), p2(maxc, -1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		p1[--a[i]] = i;
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
		p2[--b[i]] = i;
	}
	
	if (n < m) {
		swap(n, m);
		swap(a, b);
		swap(p1, p2);
	}

	int g = __gcd(n, m);
	vector<long long> eq;
	for (int i = 0; i < maxc; ++i) {
		if (p1[i] == -1 || p2[i] == -1) {
			continue;
		}
		if (p1[i] % g != p2[i] % g) {
			continue;
		}
		int q = (p2[i] - p1[i]) / g;
		int x, y;
		my_gcd(n, m, x, y);
		x *= q;
		y *= q;
		y *= -1;
		int qq = n / g;
		if (y > qq) {
			y = (y % qq + qq) % qq;
		}
		if (y < 0) {
			y = (y % qq + qq) % qq;
		}
		eq.push_back(y * m + p2[i]);
	}
	sort(eq.begin(), eq.end());
	
	int real = n * m / g;
	auto calc = [&](int mid) {
		int rr = mid / real;
		int rm = mid % real;
		int now = rr * (real - len(eq));
		
		if (!rm) {
			return now;
		}
		--rm;
		auto p = upper_bound(eq.begin(), eq.end(), rm);
		if (p == eq.begin()) {
			return now + rm + 1;
		}
		return now + (rm - (p - eq.begin()) + 1);
	};

	int low = 0, high = 1e18;
	while (high - low > 0) {
		int mid = (low + high) >> 1;
		if (calc(mid) >= k) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}

	cout << low;
}