#include <bits/stdc++.h>
using namespace std;

template<class T, class... Args>
auto VECTOR(size_t n, Args&&... args) {
if constexpr(sizeof...(args) == 1) return vector<T>(n, args...);
else return vector(n, VECTOR<T>(args...)); }

typedef long long ll;
typedef long double ld;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)
#define repr(x, y, z) for(ll (z) = (x); (z) >= (y); (z)--)
#define SIZE(x) ((ll)x.size())

ll constexpr N = 1e5;
ll constexpr MOD = 1e9 + 7;
ll constexpr INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    auto Solve = []() {
        ll n, s, k;
        cin >> n >> s >> k;
        vector<ll> in(k);
        rep (0, k, i) cin >> in[i];
        rep (0, k + 1, i) {
            if (s - i >= 1LL && find(all(in), s - i) == in.end()) return cout << i << '\n', 0;
            if (s + i <= n && find(all(in), s + i) == in.end()) return cout << i << '\n', 0;
        }
        return 0;
    };
    int tc;
    cin >> tc;
    while (tc--) {
        Solve();
    }
    return 0;
}