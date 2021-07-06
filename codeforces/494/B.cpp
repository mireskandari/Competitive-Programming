#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

constexpr int MOD = 1000 * 1000 * 1000 + 7;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

vector<int> p_function(string s) {
	int n = len(s);
	vector<int> p(n);
	int k = p[0];
	for (int i = 1; i < n; ++i) {
		while (k > 0 && s[i] != s[k]) {
			k = p[k - 1];
		}
		if (s[i] == s[k]) {
			++k;
		}
		p[i] = k;
	}
	return p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s, t;
	cin >> s >> t;
	
	int n = len(s), m = len(t);
	vector<int> p = p_function(t + "#" + s);
	for (int i = len(t) + 1; i < len(p); ++i) {
		p[i - len(t) - 1] = p[i];
	}
	
	vector<int> dp(n), pref(n);
	dp[0] = (int) (p[0] == m);
	pref[0] = dp[0];

	int last_occ = -1;
	for (int i = 1; i < n; ++i) {
		if (p[i] == m) {
			last_occ = i;
		}

		dp[i] = dp[i - 1];
		pref[i] = pref[i - 1];
		if (last_occ != -1) {
			int f = last_occ - m + 1;
			if (f > 0) {
				add(dp[i], pref[f - 1]);
				add(dp[i], f + 1);
			} else {
				add(dp[i], 1);
			}
		}
		add(pref[i], dp[i]);
		//cerr << last_occ << ' ' << i << ' ' << dp[i] << ' ' << pref[i] << '\n';
	}

	cout << dp[n - 1];
}