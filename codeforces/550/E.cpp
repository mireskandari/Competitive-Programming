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


signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n); for (auto &i : a) cin >> i;
    int last_one = n - 1;
    while (last_one >= 0 && a[last_one] == 0) --last_one;
    if (last_one >= 0 && n - last_one == 3 && !count(a.begin(), a.begin() + last_one, 0)) {
        cout << "NO";
        exit(0);
    }
    if (a.back() == 1) {
        cout << "NO";
        exit(0);
    }
    if (n == 1) {
        cout << "YES\n" << a[0];
        exit(0);
    }
    if (n == 2) {
        if (a[0] == a[1] && a[0] == 0) {
            cout << "NO";
        } else {
            string ans = to_string(a[0]) + "->" + to_string(a[1]);
            cout << "YES\n" << ans;
        }
        exit(0);
    }
    if (n == 3) {
        string ans;
        for (int i = 0; i < n - 1; ++i) {
            ans += to_string(a[i]) + "->";
        }
        ans += to_string(a.back());
        cout << "YES\n" << ans;
        exit(0);
    }
    if (n == 4) {
        string ans;
        ans = to_string(a[0]) + "->";
        ans += "(" + to_string(a[1]) + "->" + to_string(a[2]) + ")" + "->";
        ans += to_string(a.back());
        cout << "YES\n" << ans;
        exit(0);
    }
    // god of multiple cases :/
    if (last_one == -1 || !count(a.begin(), a.begin() + last_one, 0)) {
        string ans;
        for (int i = 0; i < n - 3; ++i) {
            ans += to_string(a[i]) + "->";
        }
        ans += "(" + to_string(a[n - 3]) + "->" + to_string(a[n - 2]) + ")->";
        ans += to_string(a.back());
        cout << "YES\n" << ans;
        exit(0);

    }
    while (last_one >= 0 && a[last_one] == 1) --last_one;
    string ans;
    for (int i = 0; i < last_one; ++i) {
        ans += to_string(a[i]) + "->";
    }
    ans += "(" + to_string(a[last_one]) + "->(";
    for (int i = last_one + 1; i < n - 1; ++i) {
        ans += to_string(a[i]);
        if (i != n - 2) ans += "->";
    }
    ans += "))";
    ans += "->" + to_string(a.back());
    cout << "YES\n" << ans;
    return 0;
}