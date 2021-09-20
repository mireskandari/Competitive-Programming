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
		for (int i = 0; i < n; ++i) {
			cout << "()";
		}
		cout << '\n';
		for (int i = 0; i < n - 1; ++i) {
			for (int j = 0; j < i; ++j) {
				cout << "()";
			}
			cout << "(())";
			for (int j = n - 3 - i; j >= 0; --j) {
				cout << "()";
			}
			cout << '\n';
		}
	}
}