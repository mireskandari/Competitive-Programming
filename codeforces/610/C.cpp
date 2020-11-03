#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define ERR(...) fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")

int main() {
	int k;
	scanf("%d", &k);
	if (k == 0) {
		puts("+");
		exit(0);
	}
	function<vector<string>(int)> Make = [&](int n) {
		if (n == 1) return vector<string>{"+*", "++"};
		auto a = Make(n - 1);
		auto b = a;
		for (auto& s : b) {
			for (auto& c : s) c = (char)((int)'+' + '*' - c);
		}
		vector<string> ret;
		for (auto s : a) ret.push_back(s + s);
		for (int i = 0; i < (int)a.size(); ++i) ret.push_back(a[i] + b[i]);
		return ret;
	};
	auto a = Make(k);
	for (auto s : a) printf("%s\n", s.c_str());
	return 0;
}
