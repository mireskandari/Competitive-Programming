#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void debug() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug(Head H, Tail... T) { cerr << H << ' '; debug(T...); }
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        cout << ((n ^ k) & 1 || static_cast<int>(sqrt(n)) < k ? "NO\n" : "YES\n");
    }
    return 0;
}