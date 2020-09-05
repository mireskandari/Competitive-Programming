#include <bits/stdc++.h>
using namespace std;

namespace Util {
#ifdef LOCAL
#define dbg(a) cerr << __LINE__ << " \"" << #a << "\": " << a << '\n'
#else
#define dbg(a) 0
#endif

#define all(v) (v).begin(), (v).end()
#define long int64_t
}
using namespace Util;

vector<vector<int>> base1{{1}};

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> prv = base1;
    for (int i = 3; i <= n; i += 2) {
        vector<vector<int>> a(i, vector<int>(i));
        vector<int> odd, even; odd.reserve(i), even.reserve(i);
        for (int j = (i - 2) * (i - 2) + 1; j <= i * i; j += 2) even.emplace_back(j);
        for (int j = (i - 2) * (i - 2) + 2; j <= i * i; j += 2) odd.emplace_back(j);
        int xx = (i + 1) / 2;
        xx = xx & 1;
        for (int j = 0, x = xx; j < i; ++j) {
            if (x) {
                a[i - 1][j] = odd.back(); odd.pop_back();
            } else {
                a[i - 1][j] = even.back(); even.pop_back();
            }
            x ^= 1;
        }
        for (int j = 0, x = xx; j < i; ++j) {
            if (x) {
                a[0][j] = odd.back(); odd.pop_back();
            } else {
                a[0][j] = even.back(); even.pop_back();
            }
            x ^= 1;
        }
        for (int j = 1, x = !xx; j < i - 1; ++j) {
            if (x) {
                a[j][0] = odd.back(); odd.pop_back();
            } else {
                a[j][0] = even.back(); even.pop_back();
            }
            x ^= 1;
        }
        for (int j = 1, x = !xx; j < i - 1; ++j) {
            if (x) {
                a[j][i - 1] = odd.back(); odd.pop_back();
            } else {
                a[j][i - 1] = even.back(); even.pop_back();
            }
            x ^= 1;
        }
        // fuck life
        for (int j = 1; j < i - 1; ++j) {
            for (int x = 1; x < i - 1; ++x) {
                a[j][x] = prv[j - 1][x - 1];
            }
        }
        swap(prv, a);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << prv[i][j] << " \n"[j == n - 1];
        }
    }
    return 0;
}
