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
    ll n;
    vector<ll> divv;
    cin >> n;
    auto isp = [&]() {
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                divv.push_back(i);
                if (i * i != n) divv.push_back(n / i);
            }
        }
        return divv.empty();
    };

    if (isp()) return cout << n, 0;
    else {
        ll a = 0;
        for (auto d : divv) {
            a = __gcd(d, a);
            if (a == 1) return cout << 1, 0;
        }
        cout << divv[0];
    }
    return 0;
}