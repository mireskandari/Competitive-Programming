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
    vector<int> temp(n);
    auto Solve = [&](auto &slf, int l, int r) {
        if (r - l <= 1) return 0ll;
        int m = (l + r) >> 1;
        ll ret = slf(slf, l, m);
        ret += slf(slf, m, r);
        int i = l, j = m, p = l;
        while (i < m && j < r) {
            if (a[i] > a[j]) {
                temp[p++] = a[j++];
                ret += m - i;
            } else {
                temp[p++] = a[i++];
            }
        }
        while (i < m) temp[p++] = a[i++];
        while (j < r) temp[p++] = a[j++];
        for (int k = l; k < r; ++k)
            a[k] = temp[k];
        return ret;
    };
    cout << Solve(Solve, 0, n) << ' ' << x;
    return 0;
}
