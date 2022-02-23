#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int a[3][2];
		int mx = 0;
		for (int i = 0; i < 3; ++i) {
			cin >> a[i][0] >> a[i][1];
			mx = max(a[i][1], mx);
		}
		vector<int> t;
		for (int i = 0; i < 3; ++i) {
			if (a[i][1] == mx) {
				t.push_back(i);
			}
		}
		if ((int) t.size() == 1) {
			cout << 0 << '\n';
			continue;
		}
		cout << abs(a[t[0]][0] - a[t[1]][0]) << '\n';
	}
}