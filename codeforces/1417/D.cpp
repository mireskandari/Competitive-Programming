#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        ll sum = accumulate(begin(a), end(a), 0ll);
        if (sum % n != 0) {
            cout << -1 << '\n';
            continue;
        }
        int elem = sum / n;
        struct Q { int i, j, x; };
        vector<Q> ans;
        ans.reserve(3 * n);
        for (int i = 2; i <= n; ++i) {
            if (a[i] % i != 0) {
                ans.push_back(Q{1, i, i - a[i] % i});
                a[i] += i - a[i] % i;
            }
            ans.push_back(Q{i, 1, a[i] / i});
        }
        for (int i = 2; i <= n; ++i)
            ans.push_back(Q{1, i, elem});
        cout << ans.size() << '\n';
        for (auto &i : ans)
            cout << i.i << ' ' << i.j << ' ' << i.x << '\n';
    }
    return 0;
}
