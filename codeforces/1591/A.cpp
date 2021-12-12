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
		int now = 1;
		bool was = false;
		for (int i = 0; i < n; ++i) {
			int is;
			cin >> is;
			if (is) {
				if (was) {
					now += 5;
				} else {
					now++;
				}
				was = true;
			} else {
				if (i != 0 && !was) {
					for (int j = i + 1; j < n; ++j) {
						int tmp;
						cin >> tmp;
					}
					now = -1;
					break;
				}
				was = false;
			}
		}
		cout << now << '\n';
	}
}