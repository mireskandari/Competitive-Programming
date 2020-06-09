#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

vector<vector<int>> base = {{9, 6, 5}, {7, 2, 8}, {1, 3, 4}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n < 3) {
        cout << -1;
        return 0;
    }
    bool u = !(n & 1);
    vector ans(n, vector(n, 0));
    int now = 1;
    for (int i = n - 1; i > 2; i--) {
        if (u) {
            for (int x = 0; x <= i; x++) {
                ans[x][i] = now++;
            }
            for (int y = i - 1; y >= 0; y--) {
                ans[i][y] = now++;
            }
        } else {
            for (int y = 0; y <= i; y++) {
                ans[i][y] = now++;
            }
            for (int x = i - 1; x >= 0; x--) {
                ans[x][i] = now++;
            }
        }
        u = !u;
    }
    for (auto &v : base) {
        for (auto &i : v) i += now - 1;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ans[i][j] = base[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}