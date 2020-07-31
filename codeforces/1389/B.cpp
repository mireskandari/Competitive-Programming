#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
#define X first
#define Y second

using ll = long long; using ld = long double;

template <class T = int> using V = vector<T>;
template <class T = int> using VV = V<V<T>>;
template <class T = int> using PP = pair<T, T>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k, z;
    cin >> n >> k >> z;
    V<> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    if (z == 0) {
      cout << accumulate(a.begin(), a.begin() + k + 1, 0LL) << '\n';
    } else {
      V<ll> pref(n);
      for (int i = 0; i < n; i++) {
        pref[i] = (i != 0 ? pref[i - 1] : 0) + a[i];
      }
      auto gsum = [&](int l, int r) {
        if (l > r) return 0LL;
        return pref[r] - (l ? pref[l - 1] : 0);
      };
      ll mx = accumulate(a.begin(), a.begin() + k + 1, 0LL);
      for (int i = 0; i < k; i++) {
        int rm_moves = k - i;
        ll coeff = min(z, rm_moves / 2);
        rm_moves -= coeff * 2;
        mx = max(mx, gsum(0, i) + a[i] * coeff + a[i + 1] * coeff + gsum(i + 1, rm_moves + i));
      }

      cout << mx << '\n';
    }
  }
  return 0;
}
