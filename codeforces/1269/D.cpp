#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // first black
    long long b = 0, w = 0;
    b = (a[0] + 1) / 2, w = a[0] / 2;
    int last = 0;
    for (int i = 1; i < n; i++) {
        bool par = (a[i] & 1) == (a[i - 1] & 1);
        if ((par && last == 0) || (!par && last == 1)) {
            w += (a[i] + 1) / 2;
            b += a[i] / 2;
        } else {
            b += (a[i] + 1) / 2;
            w += a[i] / 2;
        }
        if (par) {
            last = !last;
        }
    }
    long long ans = min(b, w);
    // first white
    w = (a[0] + 1) / 2, b = a[0] / 2;
    last = 1;
    for (int i = 1; i < n; i++) {
        bool par = (a[i] & 1) == (a[i - 1] & 1);
        if ((par && last == 0) || (!par && last == 1)) {
            w += (a[i] + 1) / 2;
            b += a[i] / 2;
        } else {
            b += (a[i] + 1) / 2;
            w += a[i] / 2;
        }
        if (par) {
            last = !last;
        }
    }
    ans = max(min(b, w), ans);
    cout << ans;
    return 0;
}