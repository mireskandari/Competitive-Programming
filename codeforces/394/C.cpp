#include <bits/stdc++.h>
using namespace std;

template <class T> int size(const T& a) { return a.size(); }
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int cnt[3] = {};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			if (x == 0)
				cnt[2]++;
			else if (x == 10 || x == 1)
				cnt[1]++;
			else
				cnt[0]++;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (cnt[0] > 0) {
				cout << "11 ";
				--cnt[0];
			} else if (cnt[1] > 0) {
				if ((m - j) <= cnt[1]) {
					if (i & 1)
						cout << "10 ";
					else
						cout << "01 ";
					--cnt[1];
				} else {
					cout << "00 ";
				}
			} else {
				cout << "00 ";
			}
		}
		cout << "\n";
	}
	return 0;
}