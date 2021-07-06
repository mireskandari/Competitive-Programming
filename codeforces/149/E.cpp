#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

string reversed(string s) {
	reverse(s.begin(), s.end());
	return s;
}

vector<int> p_function(string s) {
	int n = len(s);

	vector<int> p(n, 0);
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
	
	string s;
	cin >> s;
	int m;
	cin >> m;
	int n = len(s);

	int ans = 0;

	while (m--) {
		string t;
		cin >> t;
		
		auto lr = p_function(t + "#" + s);
		auto rl = p_function(reversed(t) + "#" + reversed(s));
		
		reverse(rl.begin(), rl.end());
		for (int i = len(t) + 1; i < len(lr); ++i) {
			lr[i - len(t) - 1] = lr[i];
		}

		for (int i = 0; i < n - 1; ++i) {
			lr[i + 1] = max(lr[i], lr[i + 1]);
		}
		for (int i = n - 1; i > 0; --i) {
			rl[i - 1] = max(rl[i], rl[i - 1]);
		}
		
		bool ok = false;
		for (int i = 1; i < n; ++i) {
			//cerr << i << ' ' << s[i] << ' ' << lr[i - 1] << ' ' << rl[i + 1] << '\n';
			if (len(t) > 1 && lr[i - 1] + rl[i] >= len(t)) {
				ok = true;
				break;
			}
		}
	
		ans += (int) ok;
		//cerr << ok << '\n';
	}

	cout << ans;
}