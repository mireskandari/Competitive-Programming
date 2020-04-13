#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    vector<bool> mark(n + 1, false);
    for (auto divv : {a, b, c, d}) {
        for (int i = divv; i <= n; i += divv) {
            mark[i] = true;
        }
    }
    cout << count(1 + mark.begin(), mark.end(), true);
    return 0;
}