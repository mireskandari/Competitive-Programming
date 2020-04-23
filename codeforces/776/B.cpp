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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> in(n + 3);
    iota(2 + all(in), 2);
    vector<int> col(n + 3, 0);
    auto Sieve = [&]() {
        for (ll i = 2; i * i <= n + 1; i++) {
            if (col[i] == 0) {
                for (ll j = 2 * i; j <= n + 1; j += i) {
                    col[j] = 1;
                }
            }
        }
    };
    Sieve();
    cout << *max_element(all(col)) + 1 << '\n';
    rep (2, n + 2, i) cout << col[i] + 1 << ' ';
    return 0;
}