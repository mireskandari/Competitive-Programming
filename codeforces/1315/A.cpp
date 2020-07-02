#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

#define all(v) (v).begin(), (v).end()
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	auto &&run_case = []() {
		long long a, b, x, y;
		cin >> a >> b >> x >> y;
		long long ans = x * b;
		ans = max(ans, (a - x - 1) * b);
		ans = max(ans, y * a);
		ans = max(ans, (b - y - 1) * a);
		cout << ans << '\n';
	};

	int tc;
	cin >> tc;
	while (tc--) run_case();
	
    return 0;
}
