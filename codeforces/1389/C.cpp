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
    string s;
    cin >> s;
    int n = (int) s.size();
    int mx = INT_MIN;
    for (int i = 0; i < 10; i++) {
      mx = max(mx, (int) count(all(s), (char) ('0' + i)));
    }

    int mx2 = INT_MIN;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        if (i == j) continue;
        auto solve = [&](int p) {
          int sz = 0;
          for (int x = 0; x < n; x++) {
            if (p && s[x] == (char) ('0' + i)) {
              sz++;
              p ^= 1;
            } else if (!p && s[x] == (char) ('0' + j)) {
              sz++;
              p ^= 1;
            }
          }
          if (sz & 1) sz--;
          return sz;
        };
        
        mx2 = max({mx2, solve(0), solve(1)});
      }
    }
        
    cout << min({n - mx, n - mx2, n - 2}) << '\n';
  }
  return 0;
}
