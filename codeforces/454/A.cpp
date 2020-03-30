#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    rep (0, n / 2, i) {
        cout << string((n - (i * 2 + 1)) / 2, '*') + string(i * 2 + 1, 'D') + string((n - (i * 2 + 1)) / 2, '*') + '\n';
    }
    cout << string(n, 'D') + '\n';
    for (int i = n / 2 - 1; i >= 0; i--) {
        cout << string((n - (i * 2 + 1)) / 2, '*') + string(i * 2 + 1, 'D') + string((n - (i * 2 + 1)) / 2, '*') + '\n';
    }
    return 0;
}