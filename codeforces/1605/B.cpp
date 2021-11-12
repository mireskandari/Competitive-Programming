#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		string s;
		cin >> n >> s;
		int c0 = count(s.begin(), s.end(), '0');
		vector<int> x;
		for (int i = 0; i < c0; ++i) {
			if (s[i] != '0') {
				x.push_back(i + 1);
			}
		}
		for (int i = c0; i < n; ++i) {
			if (s[i] != '1') {
				x.push_back(i + 1);
			}
		}
		if (x.empty()) {
			cout << 0 << '\n';
		} else {
			cout << 1 << '\n' << x.size() << ' ';
			for (auto &i : x) {
				cout << i << ' ';
			}
			cout << '\n';
		}
	}
}