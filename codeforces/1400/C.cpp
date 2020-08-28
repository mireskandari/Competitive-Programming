#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
template <class T = int> using vc = vector<T>;
template <class T = int> using pp = pair<T, T>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc; cin >> tc;
  while (tc--) {
    string s; cin >> s;
    int n = (int) s.size();
    int x; cin >> x;
    string ans(n, '1');
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        if (i + x < n) ans[i + x] = '0';
        if (i - x >= 0) ans[i - x] = '0';
      }
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      bool b1 = s[i] == '0' && ((i + x < n && ans[i + x] == '1') || (i - x >= 0 && ans[i - x] == '1'));
      bool b2 = s[i] == '1' && ((i + x >= n || ans[i + x] == '0') && (i - x < 0 || ans[i - x] == '0'));
      if (b1 || b2) {
        cout << -1 << '\n';
        ok = false;
        break;
      }
    }
    if (!ok) continue;
    cout << ans << '\n';
  }
  return 0;
}
