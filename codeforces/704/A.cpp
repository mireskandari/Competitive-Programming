#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return a.size(); }

const int N = 3e5 + 10;

int n, q;
set<pair<int, int>> a;
deque<int> b[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> q;
	int i = 0;
	while (q--) {
		int t, x;
		cin >> t >> x;
		if (t == 1) {
			a.insert({i, --x});
			b[x].push_back(i++);
		} else if (t == 2) {
			--x;
			for (auto &i : b[x]) {
				a.erase({i, x});
			}
			while (!b[x].empty()) {
				b[x].pop_back();
			}
		} else {
			--x;
			auto it = a.upper_bound(make_pair(x, INT_MAX));
			vector<pair<int, int>> aux;
			for (auto it1 = a.begin(); it1 != it; ++it1) {
				int y = it1->second;
				b[y].pop_front();
				aux.push_back(*it1);
			}
			for (auto &p : aux) {
				a.erase(p);
			}
		}
		cout << len(a) << '\n';
	}
}