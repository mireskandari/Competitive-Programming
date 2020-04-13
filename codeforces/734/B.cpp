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

    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    ll sum = 0;
    while (min({k2, k5, k6}) > 0) {
        k2--; k5--; k6--;
        sum += 256;
    }
    while (min(k3, k2) > 0) {
        k3--; k2--;
        sum += 32;
    }
    cout << sum;
    return 0;
}