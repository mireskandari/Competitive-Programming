#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <bits/extc++.h>
using namespace __gnu_pbds;
using pbds = tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i; 
    int x = 0;
    vector<vector<int>> seg;
    {
        vector<int> tmp(n);
        iota(begin(tmp), end(tmp), 0);
        seg.push_back(tmp);
    }
    for (int j = 31; j >= 0; --j) {
        ll inv[2] = {};
        for (auto &s : seg) {
            int cnt[2] = {};
            for (auto &i : s) {
                if ((a[i] >> j) & 1) {
                    ++cnt[1];
                    inv[1] += cnt[0];
                } else {
                    ++cnt[0];
                    inv[0] += cnt[1];
                }
            }
        }
        if (inv[0] > inv[1]) {
            x ^= 1 << j;
            for (int i = 0; i < n; ++i)
                a[i] ^= 1 << j;
        }
        vector<vector<int>> new_seg;
        for (auto &s : seg) {
            vector<int> zero, one;
            for (auto &i : s) {
                if ((a[i] >> j) & 1) one.emplace_back(i);
                else zero.emplace_back(i);
            }
            if (!one.empty()) new_seg.push_back(one);
            if (!zero.empty()) new_seg.push_back(zero);
        }
        swap(seg, new_seg);
    } 
    ll inv = 0;
    pbds s;
    for (int i = 0; i < n; ++i) {
        inv += s.order_of_key({-a[i] - 1, INT_MAX});
        s.insert({-a[i], i});
    }
    cout << inv << ' ' << x;
    return 0;
}
