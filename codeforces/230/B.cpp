#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e6 + 10;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

bool isp[N];
void prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (!isp[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                isp[j] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<ll> in(n);
    rep (0, n, i) cin >> in[i];
    prime(ceil(sqrt(*max_element(all(in)))));
    rep (0, n, i) {
        if (in[i] == 1) {
            cout << "NO\n";
            continue;
        }
        ll sq = sqrt(in[i]);
        if (sq * sq == in[i] && !isp[sq]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}