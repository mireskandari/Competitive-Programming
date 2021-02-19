#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

struct Dist {
	long long v, d;
	bool operator<(const Dist &other) const {
		return other.d < d;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long h;
	int n, m, k;
	cin >> h >> n >> m >> k;
	
	map<long long, long long> mp;
	vector<long long> a(n);
	vector<set<long long>> idx(k);
	map<long long, int> who;

	for (int i = 0; i < n; ++i) {
		long long j;
		int c;
		cin >> j >> c;
		--j;
		idx[j % k].insert(j);
		mp[j] = c;
		a[i] = j;
		who[j] = i;
	}

	vector<long long> ops{k};
	vector<long long> dp(k, h);

	dp[0] = 0;
	
	set<pair<long long, long long>> now; // costs are negative

	auto recalc = [&]() {
		priority_queue<Dist> pq;
		for (int i = 0; i < k; ++i) {
			pq.push({i, dp[i]});
		}
		while (!pq.empty()) {
			int v = pq.top().v;
			long long d = pq.top().d;
			pq.pop();
			if (d != dp[v]) {
				continue;
			}
			long long x = ops.back();
			long long nd = d + x;
			if (nd < h && dp[nd % k] > nd) {
				dp[nd % k] = nd;
				pq.push({nd % k, nd});
			}
		}
		for (int i = 0; i < k; ++i) {
			auto p = idx[i].lower_bound(dp[i]);
			vector<int> removed;
			for (auto it = p; it != idx[i].end(); ++it) {
				now.insert({-mp[*it], who[*it]});
				removed.push_back(*it);
			}
			for (auto &j : removed) {
				idx[i].erase(j);
			}
		}
	};
	
	auto change = [&](long long j, long long c) {
		int w = who[j];
		if (mp.count(j)) {
			if (now.count({-mp[j], w})) {
				now.erase({-mp[j], w});
				mp[j] = c;
				now.insert({-mp[j], w});
			} else {
				mp[j] = c;
			}
		}
	};

	recalc();

	auto debug_dp = [&]() {
		cerr << " DP\n";
		for (int i = 0; i < k; ++i) {
			cerr << dp[i] << ' ';
		}
		cerr << "\n\n\n";
		cerr << "NOW\n";
		for (auto &p : now) {
			cerr << p.first << ' ' << p.second << '\n';
		}
		cerr << "\n\n\n";
	};

	//debug_dp();

	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			long long x;
			cin >> x;
			ops.push_back(x);
			recalc();
		} else if (op == 2) {
			int x;
			long long c;
			cin >> x >> c;
			long long j = a[--x];
			change(j, mp[j] - c);
		} else {
			if (now.empty()) {
				cout << 0 << '\n';
			} else {
				cout << -now.begin()->first << '\n';
				change(a[now.begin()->second], 0);
			}
		}

		//debug_dp();
	}
}