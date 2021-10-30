#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &i : a) {
			cin >> i;
		}
		while (!a.empty()) {
			int ptr = (int) a.size() - 1;
			while (ptr >= 0 && a[ptr] % (ptr + 2) == 0) {
				--ptr;
			}
			if (ptr < 0) {
				break;
			}
			a.erase(a.begin() + ptr);
		}
		cout << (a.empty() ? "YES\n" : "NO\n");
	}
}