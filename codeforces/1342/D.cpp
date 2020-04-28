#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(int (z) = (x); (z) < (y); (z)++)
#define repr(x, y, z) for(int (z) = (x); (z) >= (y); (z)--)
#define SIZE(x) ((int)x.size())

template<class T = int, class... Args>
auto vec(size_t n, Args&&... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, T(args...));
    else
        return vector(n, vec<T>(args...));
}

ll constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
ll constexpr INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    using pii = pair<int, int>;
    int n, k;
    cin >> n >> k;
    vector<int> in(n), lim(k + 1);
    rep (0, n, i) cin >> in[i];
    rep (1, k + 1, i) cin >> lim[i];
    auto tc = vec<int>(1, 0, 0);
    tc.reserve(n);
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.emplace(0, 0);
    sort(all(in), greater<>());
    rep (0, n, i) {
        auto t = pq.top();
        if (t.X < lim[in[i]]) {
            tc[t.Y].push_back(in[i]);
            pq.pop();
            pq.emplace(t.X + 1, t.Y);
        } else {
            tc.emplace_back(1, in[i]);
            pq.emplace(1, tc.size() - 1);
        }
    }
    cout << tc.size() << '\n';
    for (const auto& v : tc) {
        cout << v.size() << ' ';
        for (auto i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}