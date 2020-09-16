#include <bits/stdc++.h>
#define dbg(a) 0
// #define dbg(a) cerr << "\"" << #a << "\":" << a << '\n'
using namespace std;
using ll = long long;
auto R_ = [] { return ios::sync_with_stdio(0), cin.tie(0); }();

void chmax(ll &a, ll b) {
    a = a > b ? a : b;
}

signed main() {
    string s;
    cin >> s;
    int n = int(s.size());
    vector<ll> cnt(26);
    for (auto &c : s) cnt[c - 'a']++;
    ll mx = *max_element(cnt.begin(), cnt.end());
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (i == j) {
                chmax(mx, (cnt[i] * (cnt[i] - 1)) / 2);
            } else {
                ll now = 0;
                vector<ll> pref(n + 1);
                for (int x = 1; x <= n; ++x) {
                    pref[x] = pref[x - 1];
                    if (s[x - 1] != char(i + 'a') && s[x - 1] != char(j + 'a')) continue;
                    if (s[x - 1] == char(i + 'a')) pref[x]++;
                    if (s[x - 1] == char(j + 'a')) now += pref[x];
                }
                chmax(mx, now);
            }
        }
    }
    cout << mx;
    return 0;
}

