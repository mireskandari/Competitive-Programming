#include <bits/stdc++.h>
using namespace std;

vector<int> a, temp;

int64_t solve(int l, int r) {
    if (r - l <= 1) return 0;
    int m = (l + r) >> 1;
    int64_t inv = 0;
    inv += solve(l, m);
    inv += solve(m, r);
    int ii = l, jj = m, p = l;
    while (ii < m && jj < r) {
        if (a[ii] > a[jj]) {
            inv += m - ii;
            temp[p++] = a[jj++];
        } else {
            temp[p++] = a[ii++];
        }
    }
    while (ii < m) temp[p++] = a[ii++];
    while (jj < r) temp[p++] = a[jj++];
    for (int i = l; i < r; ++i) {
        a[i] = temp[i];
    }
    return inv;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    a.resize(n);
    temp.resize(n);
    for (auto &i : a) cin >> i;
    int64_t inv = solve(0, n);
    if (!(n & 1)) {
        cout << (inv & 1 ? "Um_nik" : "Petr");
    } else {
        cout << (inv & 1 ? "Petr" : "Um_nik");
    }
    return 0;
}
