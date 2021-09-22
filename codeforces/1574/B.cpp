#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int a[3], m;
		cin >> a[0] >> a[1] >> a[2] >> m;
		sort(a, a + 3);
		cout << (a[0] + a[1] + a[2] - 3 >= m && m >= a[2] - a[1] - a[0] - 1 ? "yes\n" : "no\n");
	}
}