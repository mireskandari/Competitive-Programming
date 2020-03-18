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

    ll n, m;
    ll sum = 0;
    cin >> n >> m;
    vector<ll> a(n), b(n), c(n);
    forn (0, n, i) {
        cin >> a[i] >> b[i];
        c[i] = a[i] - b[i];
        sum += a[i];
    }
    sort(all(c), greater<int>());
    ll cnt = 0;
    forn (0, n, i) {
        if (sum <= m) break;
        sum -= c[i];
        cnt++;
    }
    cout << (sum <= m ? cnt : -1);
    return 0;
}