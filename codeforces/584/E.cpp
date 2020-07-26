#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
#define X first
#define Y second

using ll = long long;
using ld = long double;

template <class T = int> using V = vector<T>;
template <class T = int> using VV = V<V<T>>;
template <class T = int> using PP = pair<T, T>;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  V<> a(n), b(n);
  V<> dst(n + 1), idx(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    idx[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    dst[b[i]] = i;
  }
  // maGiC
  V<PP<>> ans;
  int cost = 0;
  for (int rep = 0; rep < 2; rep++) { 
    for (int i = 1; i <= n; i++) {
      if (dst[i] > idx[i]) {
        for (int j = idx[i] + 1; j <= dst[i]; j++) {
          if (j < idx[i] || dst[a[j]] > idx[i]) {
            continue;
          }
          ans.emplace_back(idx[i], j);
          int temp = a[j];
          swap(a[idx[i]], a[j]);
          swap(idx[i], idx[temp]);
          cost += abs(ans.back().X - ans.back().Y);
        }
      } else if (dst[i] < idx[i]) {
        for (int j = idx[i] - 1; j >= dst[i]; j--) {
          if (j > idx[i] || dst[a[j]] < idx[i]) {
            continue;
          }
          ans.emplace_back(idx[i], j);
          int temp = a[j];
          swap(a[idx[i]], a[j]);
          swap(idx[i], idx[temp]);
          cost += abs(ans.back().X - ans.back().Y);
        }
      }
    }
  }
  cout << cost << '\n' << ans.size() << '\n';
  for (auto &p : ans) {
    cout << p.X + 1 << ' ' << p.Y + 1 << '\n';
  }
  return 0;
}
