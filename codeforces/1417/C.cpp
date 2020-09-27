#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const auto IO_ = [] {
    return ios::sync_with_stdio(false), cin.tie(nullptr);
}();

signed main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<vector<int>> pos(n, vector<int>(1, -1));
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            pos[--a[i]].emplace_back(i);
        }
        for (int i = 0; i < n; ++i) {
            pos[i].emplace_back(n);
        }
        vector<int> best(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            if (int(size(pos[i])) == 2) continue;
            auto Solve = [&](int x) {
                int init = pos[i][0], mx_diff = INT_MIN;
                for (int j = 1; j < int(size(pos[i])); ++j) {
                    mx_diff = max(mx_diff, pos[i][j] - pos[i][j - 1]);
                }
                return init < x && mx_diff <= x;
            };
            int low = 1, high = n;
            while (high - low > 1) {
                int mid = (high + low) >> 1;
                if (Solve(mid)) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
            if (!Solve(low)) low = high;
            assert(low >= 1 && low <= n);
            best[low - 1] = min(best[low - 1], i);
        }
        int last = INT_MAX;
        for (auto &i : best) {
            i = min(i, last);
            cout << (i == INT_MAX ? -1 : i + 1) << ' ';
            last = min(i, last);
        }
        cout << '\n';
    }
    return 0;
}
