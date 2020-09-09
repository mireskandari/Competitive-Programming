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

ll ask(ll i, ll j) {
    cout << "? " << i + 1 << ' ' << j + 1 << endl;
    ll x;
    cin >> x;
    if (x == -1) exit(0);
    return x;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    ll n;
    cin >> n;
    if (n == 1) {
        cout << "! 1" << endl;
        exit(0);
    }

    vector<ll> a(n, -1);
    vector<ll> ind(n);
    iota(all(ind), 0);

    while ((int) ind.size() > 1) {
        ll x = ind[(int) ind.size() - 1];
        ll y = ind[(int) ind.size() - 2];
        ind.pop_back();
        ind.pop_back();
        
        ll f = ask(x, y), s = ask(y, x);
        if (f > s) {
            a[x] = f;
            ind.emplace_back(y);
        } else {
            a[y] = s;
            ind.emplace_back(x);
        }
    }
    
    ll mxi = max_element(all(a)) - a.begin();
    ll f = ask(mxi, ind[0]), s = ask(ind[0], mxi);
    if (f > s) {
        *find(all(a), -1) = n;
    } else {
        *find(all(a), -1) = s;
    }
    
    cout << "! ";
    for (auto &i : a) cout << i << ' ';
    cout << endl;
    return 0;
}
