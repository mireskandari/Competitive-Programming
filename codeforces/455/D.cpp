#include <bits/stdc++.h>
using namespace std;
#define cerr cerr << "DEBUG "

constexpr int N = 1e5 + 10, SQ = 350;

int n, q;
deque<int> nums[N];
int cnt[N / SQ + 1][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		cnt[i / SQ][a]++;
		nums[i / SQ].push_back(a);
	}

	cin >> q;
	int lastans = 0;
	while (q--) {
		int op, l, r;
		cin >> op;
		cin >> l >> r;
		l = (l + lastans - 1) % n, r = (r + lastans - 1) % n;
		if (l > r) {
			swap(l, r);
		}
		int fb = l / SQ, lb = r / SQ;
	//	cerr << l << ' ' << r << '\n';
		if (op == 1) {
			if (fb == lb) {
				rotate(nums[fb].begin() + (l % SQ), nums[fb].begin() + (r % SQ), nums[fb].begin() + (r % SQ) + 1);
			} else {
				int num = nums[lb][r % SQ];
				nums[fb].insert(nums[fb].begin() + (l % SQ), num);
				nums[lb].erase(nums[lb].begin() + (r % SQ));
				cnt[lb][num]--;
				cnt[fb][num]++;
				for (int i = fb + 1; i <= lb; ++i) {
					num = nums[i - 1].back();
					nums[i - 1].pop_back();
					cnt[i - 1][num]--;
					nums[i].push_front(num);
					cnt[i][num]++;
				}
			}
		} else {
			int k;
			cin >> k;
			k = (k + lastans - 1) % n + 1;
			//cerr << l << ' ' << r << ' ' << k << '\n';
			int ans = 0;
			if (fb == lb) {
				for (int i = l % SQ, e = r % SQ; i <= e; ++i) {
					if (nums[fb][i] == k) {
						ans++;
					}
				}
			} else {
				for (int i = l % SQ; i < (int) nums[fb].size(); ++i) {
					if (nums[fb][i] == k) {
						ans++;
					}
				}
				for (int i = 0, e = r % SQ; i <= e; ++i) {
					if (nums[lb][i] == k) {
						ans++;
					}
				}
				for (int i = fb + 1; i <= lb - 1; ++i) {
					ans += cnt[i][k];
				}
			}
			cout << ans << '\n';
			swap(lastans, ans);
		}
		/*for (int i = 0; i < N; ++i) {
			for (auto &j : nums[i]) {
				cout << j << ' ';
			}
		}
		cout << '\n';*/
	}
}

