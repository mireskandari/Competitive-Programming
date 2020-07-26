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

template<class T = int>
using V = vector<T>;
template<class T = int>
using VV = V<V<T>>;
template<class T = int>
using PP = pair<T, T>;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    
    VV<> has(20, V<>(20, false));
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (a[i] > b[i]) {
        ok = false;
        break;
      }
      if (a[i] != b[i]) {
        has[a[i] - 'a'][b[i] - 'a'] = true;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    
    int ans = 0;
    for (int i = 0; i < 20; i++) {
      for (int j = 0; j < 20; j++) {
        if (!has[i][j]) continue;
        ans++;
        for (int x = j + 1; x < 20; x++) {
          if (has[i][x]) {
            has[i][x] = false;
            has[j][x] = true;
          }
        }
      }
    }
    
    cout << ans << '\n';
  }
  return 0;
}
