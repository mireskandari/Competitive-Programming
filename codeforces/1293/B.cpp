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
    
    int n;
    cin >> n;
    ld ans = 0;
    rep (1, n + 1, i) {
        ans += 1.0 / ld(i);
    }
    cout << fixed << setprecision(15) << ans;
    return 0;
}