#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 2) return cout << "1 2", 0;
    long long sum = accumulate(a.begin(), a.end(), 0) / (n / 2);
//    cout << sum << '\n';
    vector<bool> mark(n, false);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (!mark[i] && !mark[j] && a[i] + a[j] == sum) {
                cout << i + 1 << ' ' << j + 1 << '\n';
                mark[i] = mark[j] = true;
                if (++cnt == n / 2) return 0;
                break;
            }
        }
    }
    return 0;
}