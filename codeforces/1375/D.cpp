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
    int n;
    cin >> n;
    V<> a(n);
    for (auto &i : a) cin >> i;

    auto &&find_mex = [&]() {
      V<char> mk(n + 1, false);
      for (int j = 0; j < n; j++) {
        mk[a[j]] = true;
      }
      int j = 0;
      while (j < n + 1 && mk[j]) j++;
      return j;    
    };  
    
    V<> ans;
    while (true) {
      /* for (auto &i : a) cout << i << ' ';
      cout << "\n\n\n"; */

      int m = find_mex();
      if (m == n) {
        int x = 0;
        while (x < n && a[x] == x) x++;
        if (x == n) break;
        a[x] = n;
        ans.emplace_back(x);
      } else {
        a[m] = m;
        ans.emplace_back(m);
      }
    }

    cout << ans.size() << '\n';
    for (auto &i : ans) cout << i + 1 << ' ';
    cout << '\n';
  };
  
  int tc;
  cin >> tc;
  while (tc--) run_case();
  return 0;
}
