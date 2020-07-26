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
    
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (a[i] > b[i]) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << -1 << '\n';
      continue;
    }
    
    int ans = 0;
    for (int i = 0; i < 20; i++) {
      char mn = CHAR_MAX;
      for (int j = 0; j < n; j++) {
        if (a[j] - 'a' != i || a[j] == b[j]) continue;
        mn = min<char>(mn, b[j] - 'a');
      }
      if (mn == CHAR_MAX) continue;
      ans++;
      for (int j = 0; j < n; j++) {
        if (a[j] - 'a' == i && a[j] != b[j]) a[j] = (char) (mn + 'a');
      }
    }
    
    cout << ans << '\n';
  }
  return 0;
}
