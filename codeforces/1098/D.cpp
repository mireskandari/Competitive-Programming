#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 5e5 + 10;

int q;
multiset<int> st[33];
long long sum[33];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> q;
	int n = 0;
	while (q--) {
		char op;
		cin >> op;
		int x;
		cin >> x;
		int l = __lg(x);
		if (op == '-') {
			st[l].erase(st[l].find(x));
			sum[l] -= x;
			--n;
		} else {
			st[l].insert(x);
			sum[l] += x;
			++n;
		}
		long long s = 0;
		int cnt = 0;
		for (int i = 0; i < 33; ++i) {
			if (st[i].empty()) {
				continue;
			}
			long long b = *st[i].begin();
			if (b > 2ll * s) {
				++cnt;
			}
			s += sum[i];
		}
		cout << n - cnt << '\n';
	}
}