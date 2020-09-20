#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto R_ = [] { return ios::sync_with_stdio(0), cin.tie(0); }();
#define dbg(a) cout << __LINE__ << " \"" << #a << "\":" << a << '\n'
// #define dbg(a) 0

signed main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> suff;
    suff.reserve(n - 1);
    for (int i = n - 1; i >= 0; --i) {
        if (i > 0) suff.emplace_back((i != n - 1 ? suff.back() : 0ll) + a[i]);
    }
    ll sum = suff.back() + a[0];
    sort(suff.rbegin(), suff.rend());
    cout << accumulate(suff.begin(), suff.begin() + k - 1, 0ll) + sum;
    return 0;
}

