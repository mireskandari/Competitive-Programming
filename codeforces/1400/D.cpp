#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n; cin >> n;
    vi a(n); for (auto &i : a) cin >> i;
    vector<vi> pref_cnt(n + 1, vi(n + 1));
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < n + 1; ++j) {
        pref_cnt[i][j] = pref_cnt[i - 1][j] + (a[i - 1] == j);
      }
    }
    auto cnt_range = [&](int l, int r, int A) {
      return max(0, pref_cnt[r + 1][A] - pref_cnt[l][A]);
    };
    ll cnt = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = i + 1; j < n - 1; ++j) {
        cnt += 1LL * cnt_range(0, i - 1, a[j]) * cnt_range(j + 1, n - 1, a[i]);
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}
