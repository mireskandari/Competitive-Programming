#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n, x;
		cin >> n >> x;
		map<long long, vector<int>> mp;
		vector<pair<long long, int>> a(n);
		vector<bool> mark(n);
		for (int i = 0; i < n; ++i) {
			long long x;
			cin >> x;
			a[i] = {x, i};
			mp[x].push_back(i);
		}
		sort(a.begin(), a.end());
		int need = 0;
		for (int i = 0; i < n; ++i) {
			if (mark[a[i].second]) {
				continue;
			}
			long long y = a[i].first;
			if (!mp[y * 1ll * x].empty()) {
				mark[mp[y * 1ll * x].back()] = true;
				mp[y * 1ll * x].pop_back();
			} else {
				need++;
			}
		}
		cout << need << '\n';
	}
}