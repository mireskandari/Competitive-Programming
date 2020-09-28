#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    vector<int> fen(n + 1);
    auto Modify = [&](int idx, ll val) {
        for (++idx; idx < n + 1; idx += idx & -idx) fen[idx] += val;
    };
    auto Get = [&](int idx) {
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx) ret += fen[idx];
        return ret;
    };
    {
        vector<int> temp(begin(a), end(a));
        sort(begin(temp), end(temp));
        temp.resize(unique(begin(temp), end(temp)) - begin(temp));
        for (auto &i : a) i = lower_bound(begin(temp), end(temp), i) - begin(temp);
    }
    ll inv = 0;
    for (auto &i : a) {
        inv += Get(n - 1) - Get(i);
        Modify(i, 1);
    }
    cout << inv << ' ' << x;
    return 0;
}
