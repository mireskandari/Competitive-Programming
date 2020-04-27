#include <bits/stdc++.h>
using namespace std;

template<class T = int, class... Args>
auto vec(size_t n, Args&&... args) {
if constexpr(sizeof...(args) == 1) return vector<T>(n, args...);
else return vector(n, vec<T>(args...)); }

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
    
    int n, q;
    cin >> n >> q;
    auto cnt = vec(2, n, 0);
    auto s = vec<char>(2, n, true);
    vector<int> now(1, n + 1);
    ll sum = 0;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        s[x][y] = !s[x][y];
        auto Check = [n](int x, int y) {
            return (x >= 0 && x < 2) && (y >= 0 && y < n);
        };
        if (s[x][y]) {
            sum -= cnt[x][y];
            cnt[x][y] = 0;
            rep (-1, 2, i) {
                if (i == 0) continue;
                rep (-1, 2, j) {
                    int nx = x + i, ny = y + j;
                    if (Check(nx, ny) && !s[nx][ny]) {
                        sum--;
                        cnt[nx][ny]--;
                    }
                }
            }
        } else {
            rep (-1, 2, i) {
                if (i == 0) continue;
                rep (-1, 2, j) {
                    int nx = x + i, ny = y + j;
                    if (Check(nx, ny) && !s[nx][ny]) {
                        cnt[nx][ny]++;
                        cnt[x][y]++;
                        sum += 2;
                    }
                }
            }
        }
        cout << (sum == 0 ? "yes\n" : "no\n");
    }
    return 0;
}