#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        bool can = true;
        for (int j = max(0, i - x); j < i; j++) {
            if (a[j] < a[i]) {
                can = false;
                break;
            }
        }
        for (int j = i + 1; j < min(n, i + y + 1); j++) {
            if (a[j] < a[i]) {
                can = false;
                break;
            }
        }
        if (can) {
            cout << i + 1;
            return 0;
        }
    }
    return 0;
}