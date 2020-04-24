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
    auto Solve = []() {
        int n;
        cin >> n;
        vector<ll> pos(n), in(n);
        rep (0, n, i) {
            cin >> in[i];
            pos[--in[i]] = i;
        }
        int curr = 0;
        vector<int> mark(n, false);
        while (curr < n && !mark[curr]) {
            rep (pos[curr], n, i) {
                if (mark[in[i]]) break;
                mark[in[i]] = true;
                if (in[i] != i - pos[curr] + curr) return cout << "No\n", 0;
            }
            while (curr < n && mark[curr]) curr++;
        }
        cout << "Yes\n";
        return 0;
    };
    int tc;
    cin >> tc;
    while (tc--) {
        Solve();
    }
    return 0;
}