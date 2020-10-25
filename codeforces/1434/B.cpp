#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__)

constexpr int N = 1e5 + 10;

int ans[N], ans_sz;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> oper;
	for (int i = 0; i < 2 * n; ++i) {
		char c;
		scanf(" %c", &c);
		if (c == '+') {
			oper.push_back(1);
		} else {
			int x;
			scanf("%d", &x);
			oper.push_back(-x);
		}
	}
	reverse(oper.begin(), oper.end());
	set<int> st;
	auto Fuck = [] { puts("NO"); exit(0); };
	for (auto& op : oper) {
		if (op > 0) {
			if (st.empty()) Fuck();
			ans[ans_sz++] = *st.begin();
			st.erase(st.begin());
		} else {
			if (!st.empty() && *st.begin() < -op) Fuck();
			st.insert(-op);
		}
	}
	reverse(ans, ans + ans_sz);
	puts("YES");
	for (int i = 0; i < ans_sz; ++i) {
		printf("%d ", ans[i]);
	}
	return 0;
}
