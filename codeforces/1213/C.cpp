#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << H << ' ';
    debug_out(T...);
}

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        
        ll n, m;
        cin >> n >> m;
        vector<int> per;
        vector<ll> sum(10);
        per.push_back(0);
        forn (1, 10, i) {
            per.push_back(1ll * i * m % 10);
        }
        partial_sum(all(per), sum.begin());
        cout << (n / (10 * m)) * sum.back() +
                sum[n / m % 10] << '\n';

    }
    return 0;
}