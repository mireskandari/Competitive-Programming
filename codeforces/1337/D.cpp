#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
ll constexpr INF = 1e18;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    auto calc = [](ll r, ll g, ll b) -> ll {
        return 1LL * (r - g) * (r - g) + 1LL * (r - b) * (r - b) + 1LL * (b - g) * (b - g);
    };
    while (tc--) {
        int nr, ng, nb;
        cin >> nr >> ng >> nb;
        vector<int> r(nr), g(ng), b(nb);
        rep (0, nr, i) cin >> r[i];
        rep (0, ng, i) cin >> g[i];
        rep (0, nb, i) cin >> b[i];
        sort(all(r));
        sort(all(g));
        sort(all(b));

        ll mn = INT64_MAX;
        vector<vector<int>> gems(3);
        gems[0] = r;
        gems[1] = g;
        gems[2] = b;
        while (next_permutation(all(gems))) {}
        do {
            r = gems[0];
            g = gems[1];
            b = gems[2];
            nr = r.size();
            ng = g.size();
            nb = b.size();
            rep (0, nr, i) {
                auto gp = lower_bound(all(g), r[i]);
                auto bp = lower_bound(all(b), r[i]);
                if (gp != g.end()) {
                    if (bp != b.end()) {
                        mn = min(mn, calc(r[i], *gp, *bp));
                    }
                    if (bp != b.begin()) {
                        mn = min(mn, calc(r[i], *gp, *(bp - 1)));
                    }
                }
                if (gp != g.begin()) {
                    if (bp != b.end()) {
                        mn = min(mn, calc(r[i], *(gp - 1), *bp));
                    }
                    if (bp != b.begin()) {
                        mn = min(mn, calc(r[i], *(gp - 1), *(bp - 1)));
                    }
                }
            }
        } while (next_permutation(all(gems)));
        cout << mn << '\n';
    }
    return 0;
}