#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
template <class T> using vec = vector<T>;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    vec<array<int, 2>> a(n); for (auto &i : a) cin >> i[0] >> i[1];
    // compress coords
    vec<int> coord; coord.reserve(2 * n);
    for (auto &i : a) {
      coord.emplace_back(i[0]);
      coord.emplace_back(i[1]);
    }
    sort(all(coord));
    coord.erase(unique(all(coord)), coord.end());
    
    for (auto &i : a) {
      for (int j = 0; j < 2; ++j) {
        i[j] = lower_bound(all(coord), i[j]) - coord.begin() + 1;
      }
    }
    // do the other shit
    int maxc = 2 * n + 2;
    vec<int> r(n);
    vec<vec<int>> r_end(maxc);
    for (int i = 0; i < n; ++i) {
      r[i] = -a[i][1];
      r_end[a[i][1]].emplace_back(i);
    }
    sort(all(r));
    
    vec<vec<int>> dp(maxc, vec<int>(maxc));
    for (int i = maxc - 1; i >= 1; --i) {
      for (int j = i; j < maxc; ++j) {
        dp[i][j] = dp[i][j - 1];
        auto p  = lower_bound(all(r), -j);
        if (p == r.end() || -(*p) < i) continue;
        bool has_all = false;
        for (auto &x : r_end[-(*p)]) has_all |= (a[x][0] == i && a[x][1] == j);
        for (auto &x : r_end[-(*p)]) {
          if (a[x][0] < i || (a[x][0] == i && a[x][1] == j)) continue;
          int option = dp[a[x][0]][a[x][1]] + dp[i][a[x][0] - 1] + dp[a[x][1] + 1][j];
          dp[i][j] = max(dp[i][j], option);
        }
        if (has_all) ++dp[i][j];
      }
    }

    cout << dp[1][maxc - 1] << '\n';
  }
  return 0;
}
