#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return (int) a.size(); }

constexpr int N = 2e5 + 10;

struct Node {
	int dp[5][5];

	Node(char s = 0) {
		memset(dp, 0x3f, sizeof(dp));
		if (s == 0) {
			return;
		}
		for (int i = 0; i < 5; ++i) {
			dp[i][i] = 0;
		}
		if (s == '6') {
			dp[3][3] = 1;
			dp[4][4] = 1;
		}
		if (s == '2') {
			dp[0][1] = 0;
			dp[0][0] = 1;
		}
		if (s == '0') {
			dp[1][2] = 0;
			dp[1][1] = 1;
		}
		if (s == '1') {
			dp[2][3] = 0;
			dp[2][2] = 1;
		}
		if (s == '7') {
			dp[3][4] = 0;
			dp[3][3] = 1;
		}
	}
};

Node t[N << 2];

Node merge(Node l, Node r) {
	Node a{};
	for (int i = 0; i <= 4; ++i) {
		for (int j = 0; j <= 4; ++j) {
			for (int k = 0; k <= 4; ++k) {
				a.dp[i][j] = min(a.dp[i][j], l.dp[i][k] + r.dp[k][j]);
			}
		}
	}
	return a;
}

Node query(int c, int b, int e, int u, int v) {
	if (u <= b && e <= v) {
		return t[c];
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	if (u < m) {
		if (v > m) {
			return merge(query(l, b, m, u, v), query(r, m, e, u, v));
		} else {
			return query(l, b, m, u, v);
		}
	}
	return query(r, m, e, u, v);
}

int n, q;
string s;

void build(int c, int b, int e) {
	if (e - b == 1) {
		t[c] = Node(s[b]);
		return;
	}
	int m = (b + e) >> 1, l = c << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	t[c] = merge(t[l], t[r]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> q;
	cin >> s;
	build(1, 0, n);

	while (q--) {
		int u, v;
		cin >> u >> v;
		--u;
		auto ans = query(1, 0, n, u, v);
		
		if (ans.dp[0][4] >= (int) 1e7) {
			cout << -1 << '\n';
		} else {
			cout << ans.dp[0][4] << '\n';
		}
	}
}