#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 2e5 + 10;

int n, a[N], dpl[N], dpr[N], ll[N], rr[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] -= i;
	}
	
	memset(ll, 0x3f, sizeof(ll));
	memset(rr, 0x3f, sizeof(rr));

	for (int i = 0; i < n; ++i) {
		auto p = upper_bound(ll, ll + n, a[i]);
		dpl[i] = p - ll + 1;
		ll[p - ll] = a[i];
	}
	
	int ans = -1e9;
	for (int i = n - 1; i > 0; --i) {
		auto p = upper_bound(rr, rr + n, -a[i - 1]);
		ans = max(ans, dpl[i - 1] + (int) (p - rr));
		p = upper_bound(rr, rr + n, -a[i] - 1);
		dpr[i] = p - rr + 1;
		ans = max(ans, dpr[i]);
		rr[p - rr] = -a[i] - 1;
	}

	cout << n - ans - 1;
}