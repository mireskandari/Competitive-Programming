#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n);
		map<int, vector<int>> mp;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			mp[a[i]].push_back(i);
		}
		long long sum = 0;
		for (auto &k : mp) {
			long long s = 0;
			for (int i : k.second) {
				s += n - i;
			}
			for (int i : k.second) {
				s -= n - i;
				sum += (i + 1) * s;
			}
		}
		cout << sum << '\n';
	}
}

