#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

const auto INIT = [] { return ios::sync_with_stdio(false), cin.tie(nullptr); }();
#define ERR(a...) fprintf(stderr, a)

constexpr int N = 210;

char s[N][N];

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }
    auto a = s[0][1], b = s[1][0], c = s[n - 1][n - 2], d = s[n - 2][n - 1];
    vector<pair<int, int>> ans;
    if (int{a == '0'} + int{b == '0'} + int{c == '1'} + int{d == '1'} <= 2) {
      if (a == '0') ans.emplace_back(1, 2);
      if (b == '0') ans.emplace_back(2, 1);
      if (c == '1') ans.emplace_back(n, n - 1);
      if (d == '1') ans.emplace_back(n - 1, n);
    } else {
      if (a == '1') ans.emplace_back(1, 2);
      if (b == '1') ans.emplace_back(2, 1);
      if (c == '0') ans.emplace_back(n, n - 1);
      if (d == '0') ans.emplace_back(n - 1, n);
    }
    cout << ans.size() << '\n';
    for (auto &p : ans) {
      cout << p.first << ' ' << p.second << '\n';
    }
  }
  return 0;
}
