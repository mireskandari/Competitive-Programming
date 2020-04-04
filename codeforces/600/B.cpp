#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    auto a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stable_sort(a, a + n);
    for (int i = 0; i < m; i++) {
        int val; cin >> val;
        cout << upper_bound(a, a + n, val) - a << ' ';
    }
    return 0;
}