#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector mp(n, vector(n, 0));
        for (auto &v : mp) {
            for (auto &i : v) {
                char c;
                cin >> c;
                i = c - '0';
            }
        }
        vector can(n, vector(n, false));
        bool ok = true;
        for (int i = n - 1; i >= 0; i--) {
            for (int xi = i; xi >= 0; xi--) {
                if (mp[xi][i] == 0) continue;
                if (i == n - 1) can[xi][i] = true;
                else can[xi][i] = can[xi + 1][i] || can[xi][i + 1];
                if (!can[xi][i]) {
                    ok = false;
                    break;
                }
            }
            for (int xj = i; xj >= 0; xj--) {
                if (mp[i][xj] == 0) continue;
                if (i == n - 1) can[i][xj] = true;
                else can[i][xj] = can[i + 1][xj] || can[i][xj + 1];
                if (!can[i][xj]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}