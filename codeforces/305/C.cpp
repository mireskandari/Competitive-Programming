#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// auto R_ = [] { return ios::sync_with_stdio(0), cin.tie(0); }();
// #define dbg(a) 0
// #define dbg(a) cerr << __LINE__ << " \"" << #a << "\":" << a << '\n'

signed main() {
    ll n;
    scanf("%lld", &n);
    map<ll, ll> temp;
    for (int i = 0; i < n; ++i) {
        ll x;
        scanf("%lld", &x);
        temp[x]++;
    }
    map<ll, ll> cnt;
    while (!temp.empty()) {
        while (temp.begin()->second > 1) {
            temp[temp.begin()->first + 1]++;
            temp.begin()->second -= 2;
        }
        if (temp.begin()->second != 0) {
            cnt[temp.begin()->first] = temp.begin()->second;
        }
        temp.erase(temp.begin());
    }
    printf("%lld", cnt.rbegin()->first + 1 - (ll) cnt.size());
    return 0;
}
