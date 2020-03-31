#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    if (m % n != 0) return cout << -1, 0;
    int d = m / n;
    int dd[4] = {0, 0, 0, 0};
    for (auto i : {2, 3}) {
        while (d % i == 0) {
            d /= i;
            dd[i]++;
        }
    }
//    cout << d;
    if (d != 1) return cout << -1, 0;
//    cout << d;
    cout << dd[2] + dd[3];
    return 0;
}