#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define cerr if(0) cout
#endif

#define all(v) (v).begin(), (v).end()
#define X first
#define Y second

using ll = long long;
using ld = long double;

template<class T = int>
using V = vector<T>;
template<class T = int>
using VV = V<V<T>>;
template<class I, class J>
using P = pair<I, J>;
template<class T = int>
using PP = P<T, T>;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  auto &&run_case = [&]() {
    int n, m;
    cin >> n >> m;
    VV<> a(n, V<>(m));
    for (auto &v: a) for (auto &i : v) cin >> i;

    static int const dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    auto &&check = [&](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < m;
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int cntn = 0;
        for (int x = 0; x < 4; x++) {
          int nx = i + dx[x], ny = j + dy[x];
          if (check(nx, ny)) cntn++;
        }
        if (cntn < a[i][j]) {
          cout << "NO\n";
          return;
        }
        a[i][j] = cntn;
      }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[i][j] << ' ';
      }
      cout << '\n';
    }
  };
  
  int tc;
  cin >> tc;
  while (tc--) run_case();
  return 0;
}
