#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		string s;
		cin >> s;
		vector<int> stk;
		for (int i = 0; i < len(s); ++i) {
			if (s[i] == 'A') {
				stk.push_back(i);
			} else {
				if (!stk.empty()) {
					stk.pop_back();
				} else {
					stk.push_back(i);
				}
			}
		}
		cout << len(stk) << '\n';
	}
	return 0;
}

