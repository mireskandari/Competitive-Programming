#include <bits/stdc++.h>
using namespace std;
template <typename T> inline int len(const T &a) { return a.size(); }

constexpr int maxn = 5e6 + 10;

bool compo[maxn];
int pi[maxn];

string reversed(string s) {
	reverse(s.begin(), s.end());
	return s;
}

int main() {
	for (int i = 2; i < maxn; ++i) {
		if (!compo[i]) {
			for (int j = 2 * i; j < maxn; j += i) {
				compo[j] = true;
			}
		}
	}
	pi[1] = 0;
	for (int i = 2; i < maxn; ++i) {
		pi[i] = pi[i - 1] + !compo[i];
	}
	int p, q;
	cin >> p >> q;
	int rub = 0;
	int mx = -1;
	for (int i = 1; i < maxn; ++i) {
		if (to_string(i) == reversed(to_string(i))) {
			++rub;
		}
		if (1ll * q * pi[i] <= 1ll * p * rub) {
			mx = i;
		}
	}
	if (mx != -1) {
		cout << mx;
		exit(0);
	}
	cout << "Palindromic tree is better than splay tree";
	return 0;
}

