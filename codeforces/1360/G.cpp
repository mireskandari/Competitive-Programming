#include <bits/stdc++.h>

using namespace std;

void RunCase() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (n * a != m * b) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES\n";
    vector mp(n, vector(m + 10, 0));
    int j = 0;
    for (int i = 0; i < n; i++) {
        for (int _j = 0; _j < a; _j++, j++) {
            j %= m;
            mp[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mp[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        RunCase();
    }
    return 0;
}