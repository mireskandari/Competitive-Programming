#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10;

int n, k;
int a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	long long p = 1, ans = 0;
	int m = k == 1 ? 1 : (k == -1 ? 2 : 55);
	for (int c = 0; c < m; ++c) {
		if (abs(p) > 1e14) {
			continue;
		}
		vector<long long> pref(n);
		pref[0] = a[0];
		
		map<long long, int> st;
		st[0]++;
		for (int i = 0; i < n; ++i) {
			if (i) {
				pref[i] = pref[i - 1] + a[i];
			}
			ans += st[pref[i] - p];
			st[pref[i]]++;
		}

		p *= k;
	}

	cout << ans;
}