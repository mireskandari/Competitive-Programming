#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

typedef long long ll;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    ll ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      ans += max(0LL, a[i] - a[i + 1]);
    }
    cout << ans << '\n';
  }
  return 0;
}
