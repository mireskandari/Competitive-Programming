#include <bits/stdc++.h>
using namespace std;

namespace Util {
#ifdef LOCAL
#define dbg(a) cerr << __LINE__ << " \"" << #a << "\": " << a << '\n'
#else
#define dbg(a)
#endif

#define all(v) (v).begin(), (v).end()
using ll = int64_t;
}
using namespace Util;

ll constexpr MOD = (ll) 1e9 + 7;

void norm(ll &a) {
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}

struct Matrix {
    ll n;
    vector<vector<ll>> a;

    Matrix(ll n_) : n(n_), a(n_, vector<ll>(n_)) {}

    Matrix operator*(Matrix &b) {
        Matrix res(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    norm(res.a[i][j] += (a[i][k] * b.a[k][j]) % MOD);
        return res;
    }
};

Matrix binpow(Matrix a, ll x) {
    Matrix res(a.n);
    for (int i = 0; i < a.n; ++i) res.a[i][i] = 1;
    while (x) {
        if (x & 1) res = res * a;
        a = a * a;
        x >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    
    if (n < m) {
        cout << 1;
        exit(0);
    }

    Matrix a(m);
    a.a[m - 1][0] = a.a[m - 1][m - 1] = 1;
    for (int i = 1; i < m; ++i) a.a[i - 1][i] = 1;
    a = binpow(a, n - m + 1);
    
    ll res = 0;
    for (int i = 0; i < m; ++i) norm(res += a.a[i][m - 1]);
    cout << res;
    return 0;
}
