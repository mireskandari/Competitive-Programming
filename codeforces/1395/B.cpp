#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

typedef long long ll;

int constexpr N = 3e5 + 10;

int n, m, sx, sy;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> sx >> sy;
  --sy; --sx;

  vector<pair<int, int>> ans;
  ans.emplace_back(sx, sy);
  for (int i = sx; i >= 0; --i) {
    vector<int> idx(m);
    iota(idx.begin(), idx.end(), 0);
    int last = ans.back().second;
    rotate(idx.begin(), idx.begin() + last, idx.end());
  
    for (auto &j : idx) {
      if (i == sx && j == sy) continue;
      ans.emplace_back(i, j);
    }
  }
  for (int i = sx + 1; i < n; ++i) {
    vector<int> idx(m);
    iota(idx.begin(), idx.end(), 0);
    int last = ans.back().second;
    rotate(idx.begin(), idx.begin() + last, idx.end());
  
    for (auto &j : idx) {
      ans.emplace_back(i, j);
    }
  }

  for (auto &p : ans) cout << p.first + 1 << ' ' << p.second + 1 << '\n';
  return 0;
}
