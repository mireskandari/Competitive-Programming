#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

int solve(vector<int> &a, int l, int r) {
	if (r - l <= 1) {
		return 0;
	}
	int m = (r + l) >> 1;
	int ret = solve(a, l, m) ^ solve(a, m, r);
	vector<int> tmp;
	int pl = l, pr = m;
	while (pl != m || pr != r) {
		int ll = pl == m ? INT_MAX : a[pl];
		int rr = pr == r ? INT_MAX : a[pr];
		if (ll < rr) {
			tmp.push_back(ll);
			++pl;
		} else {
			tmp.push_back(rr);
			ret ^= (m - pl) & 1;
			++pr;
		}
	}
	for (int j = 0; j < r - l; ++j) {
		a[j + l] = tmp[j];
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		if (set<int>(a.begin(), a.end()).size() != a.size()) {
			cout << "YES\n";
			continue;
		}
		if (solve(a, 0, n)) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}