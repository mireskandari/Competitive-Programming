#include <bits/stdc++.h>

#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

using Tree = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10;

Tree st[N], st2[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> xx;
	vector<tuple<int, int, int>> q(n);
	for (int i = 0; i < n; ++i) {
		int a, t, x;
		cin >> a >> t >> x;
		xx.push_back(x);
		q[i] = {a, t, x};
	}
	
	sort(xx.begin(), xx.end());
	xx.resize(unique(xx.begin(), xx.end()) - xx.begin());
	for (int i = 0; i < n; ++i) {
		q[i] = {get<0>(q[i]), get<1>(q[i]), lower_bound(xx.begin(), xx.end(), get<2>(q[i])) - xx.begin()};
		int a = get<0>(q[i]), t = get<1>(q[i]), x = get<2>(q[i]);
		if (a == 1) {
			st[x].insert(t);
		} else if (a == 2) {
			st2[x].insert(t);
		} else {
			cout << st[x].order_of_key(t + 1) - st2[x].order_of_key(t + 1) << '\n';
		}
	}

}