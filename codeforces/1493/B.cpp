#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	vector<int> boy{0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

	int tc;
	cin >> tc;
	while (tc--) {
		[&]() {
			int h, m;
			cin >> h >> m;
			string s;
			cin >> s;
			int sh = (int) (s[0] - '0') * 10 + (int) (s[1] - '0');
			int sm = (int) (s[3] - '0') * 10 + (int) (s[4] - '0');
			
			auto cool = [&](int a, int b) {
				if (boy[a / 10] == -1 || boy[a % 10] == -1 || boy[b / 10] == -1 || boy[b % 10] == -1) {
					return false;
				}
				int x = 10 * boy[b % 10] + boy[b / 10];
				int y = 10 * boy[a % 10] + boy[a / 10];
				return x < h && y < m;
			};

			for (int j = sm; j < m; ++j) {
				if (cool(sh, j)) {
					cout << (sh / 10 == 0 ? "0" : "") << sh << ':' << (j / 10 == 0 ? "0" : "") << j << '\n';
					return;
				}
			}
			for (int i = (sh + 1) % h; ; i = (i + 1) % h) {
				for (int j = 0; j < m; ++j) {
					if (cool(i, j)) {
						cout << (i / 10 == 0 ? "0" : "") << i << ':' << (j / 10 == 0 ? "0" : "") << j << '\n';
						return;
					}
				}
			}
				
		}();
	}

}

