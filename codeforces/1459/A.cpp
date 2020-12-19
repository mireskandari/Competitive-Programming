#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T& a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string r, b;
		cin >> r >> b;
		int cnt_g = 0, cnt_l = 0, cnt_e = 0;
		for (int i = 0; i < n; ++i) {
			if (r[i] > b[i]) {
				cnt_g++;
			} else if (r[i] < b[i]) {
				cnt_l++;
			} else {
				cnt_e++;
			}
		}
		if (cnt_g == cnt_l) {
			cout << "EQUAL\n";
			continue;
		}
		cout << (cnt_g > cnt_l ? "RED\n" : "BLUE\n");
	}
	return 0;
}

