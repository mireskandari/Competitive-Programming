#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "
template <typename T> inline int len(const T &a) { return a.size(); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n, l, r;
		cin >> n >> l >> r;
		vector<int> cl(n), cr(n);
		for (int i = 0; i < l; ++i) {
			int x;
			cin >> x;
			cl[--x]++;
		}
		for (int i = 0; i < r; ++i) {
			int x;
			cin >> x;
			cr[--x]++;
		}
		vector<int> lefto, righto, lefte, righte;
		int cost = 0, sum[2][2] = {};
		for (int i = 0; i < n; ++i) {
			int x = min(cl[i], cr[i]);
			cl[i] -= x;
			cr[i] -= x;
			if (cl[i] > 0) {
				if (cl[i] & 1) {
					lefto.push_back(i);
					sum[0][1] += cl[i];
				} else {
					lefte.push_back(i);
					sum[0][0] += cl[i];
				}
			}
			if (cr[i] > 0) {
				if (cr[i] & 1) {
					righto.push_back(i);
					sum[1][1] += cr[i];
				} else {
					righte.push_back(i);
					sum[1][0] += cr[i];
				}
			}
		}
		for (int i = 0; i < min(len(lefto), len(righto)); ++i) {
			cost++;
			sum[0][1] -= cl[lefto[i]];
			sum[0][0] += cl[lefto[i]] - 1;
			cl[lefto[i]]--;
			sum[1][1] -= cr[righto[i]];
			sum[1][0] += cr[righto[i]] - 1;
			cr[righto[i]]--;
		}
		if (len(lefto) == len(righto)) {
			cost += sum[0][0] / 2 + sum[1][0] / 2;
			cout << cost << '\n';
			continue;
		}
		int diff = abs(len(lefto) - len(righto));
		if (len(lefto) > len(righto)) {
			diff = max(0, diff - sum[1][0]);	
		} else {
			diff = max(0, diff - sum[0][0]);
		}
		cost += sum[1][0] / 2 + sum[0][0] / 2 + (sum[1][1] + sum[0][1] - diff) / 2 + diff;
		cout << cost << '\n';
	}
}

