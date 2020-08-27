#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
typedef long long ll;
template <class T = int> using vc = vector<T>;
template <class T = int> using pp = pair<T, T>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    vc<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
    }
    vc<vc<ll>> dp(n, vc<ll>(5, 1e15));
    for (int i = 0; i < 5; ++i) dp[0][i] = i * b[0];
    auto chmin = [](auto &A, auto B) {
      A = A > B ? B : A;
    };
    for (int i = 0; i < n - 1; ++i) {
      for (int j = 0; j < 5; ++j) {
        ll cur = a[i] + j;
        for (int x = 0; x < 5; ++x) {
          ll nex = a[i + 1] + x;
          chmin(dp[i + 1][x], cur == nex ? (ll) (1e15) : dp[i][j] + b[i + 1] * x);
        }
      }
    }
    cout << *min_element(all(dp[n - 1])) << '\n';
  }
  return 0;
}
