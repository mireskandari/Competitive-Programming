#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	for (auto &i : p) {
		cin >> i;
	}
	vector<long long> pref(n);
	pref[0] = p[0];
	for (int i = 1; i < n; ++i) {
		pref[i] = pref[i - 1] + p[i];
	}
	
	vector<int> x(m);
	for (auto &i : x) {
		cin >> i;
	}
	x.push_back(-1e9);
	x.push_back(1e9 + 1);
	sort(x.begin(), x.end());

	vector<long long> l(n);
	vector<long long> r(n);
	for (int i = 0; i < n; ++i) {
		l[i] = *prev(upper_bound(x.begin(), x.end(), i * 100));
		r[i] = *lower_bound(x.begin(), x.end(), i * 100);
	}

	long long best = 0;
	for (int i = 0; i < n; ++i) {
		long long j = i * 100;
		long long d = min(j - l[i], r[i] - j);
		long long v = j + d;
		long long low = (v + 99) / 100, high = r[i] / 100;
		if (d == 0) {
			continue;
		}
		if (low >= n || min(low * 100 - l[low], r[i] - low * 100) <= low * 100 - v) {
			best = max(best, pref[min<long long>(n - 1, max(0ll, low - 1))] - (i ? pref[i - 1] : 0ll));
			continue;
		}
		while (high - low > 0) {
			long long mid = (low + high + 1) / 2;
			if (mid >= n || min(mid * 100 - l[mid], r[mid] - mid * 100) <= mid * 100 - v) {
				high = mid - 1;
			} else {
				low = mid;
			}
		}
		//cerr << low << '\n';
		best = max(best, pref[low] - (i ? pref[i - 1] : 0ll));
	}
		
	cout << best;

}