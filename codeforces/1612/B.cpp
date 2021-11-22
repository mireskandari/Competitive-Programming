#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n, a, b;
		cin >> n >> a >> b;
		if (a - b > 1) {
			cout << "-1\n";
			continue;
		}
		vector<int> f, s;
		if (a - b != 1) {
			f.push_back(a);
			s.push_back(b);
		}
		for (int i = b + 1; i <= n; ++i) {
			f.push_back(i);
		}
		for (int i = a - 1; i >= 1; --i) {
			s.push_back(i);
		}
		if ((int) f.size() > n / 2 || (int) s.size() > n / 2) {
			cout << "-1\n";
			continue;
		}
		for (int i = min(a + 1, b + 1); i < max(b, a); ++i) {
			if ((int) s.size() == n / 2) {
				f.push_back(i);
			} else {
				s.push_back(i);
			}
		}
		if ((int) f.size() != n / 2 || (int) s.size() != n / 2) {
			cout << "-1\n";
		} else {
			for (int i = 0; i < (int) f.size(); ++i) {
				cout << f[i] << ' ';
			}
			for (int i = 0; i < (int) s.size(); ++i) {
				cout << s[i] << ' ';
			}
			cout << '\n';
		}
	}
}