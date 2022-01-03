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
		set<int> tmp;
		for (int i = 0; i < n; ++i) {
			tmp.insert(i);
		}
		cout << "? " << 1 << endl;
		int xx;
		cin >> xx;
		vector<bool> mark(n);
		vector<int> f(n, -1);
		while ((int) tmp.size() > 1) {
			int i = *tmp.begin();
			cout << "? " << i + 1 << endl;
			int last;
			cin >> last;
			if (last == 0) {
				exit(0);
			}
			--last;
			while ((int) tmp.size() > 1) {
				cout << "? " << i + 1 << endl;
				int x;
				cin >> x;
				if (x == 0) {
					exit(0);
				}
				--x;
				//cerr << mark[last] << ' ' << mark[x] << ' ' << last << ' ' << x << '\n';
				f[last] = x;
				tmp.erase(last);
				mark[last] = true;
				if (last == x) {
					break;
				}
				if (mark[x]) {
					break;
				}
				last = x;
			}
		}
		long long sum = accumulate(f.begin(), f.end(), 0ll) + 1;
		f[*tmp.begin()] = 1ll * n * (n - 1) / 2 - sum;
		cout << "! ";
		for (auto &i : f) {
			cout << i + 1 << ' ';
		}
		cout << endl;
	}
}