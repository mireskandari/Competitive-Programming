#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long l, r;
	cin >> l >> r;
	cout << (l == r ? 0ll : (1ll << (64 - __builtin_clzll(l ^ r))) - 1);
}