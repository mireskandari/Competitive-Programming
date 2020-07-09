#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#endif

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
template<class I, class J>
using P = pair<I, J>;
template<class T = int>
using PP = P<T, T>;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  auto &&run_case = [&]() {
    ll k, n, a, b;
    cin >> k >> n >> a >> b;

    if (n * b >= k) {
      cout << -1 << '\n';
      return;
    }
    
    auto &&solve = [&](ll m) {
      return m * a + (n - m) * b < k;
    };

    ll h = n, l = 0;
    for (int i = 0; i < 40; i++) {
      ll m = (h + l) >> 1;
      if (solve(m)) {
        l = m;
      } else {
        h = m;
      }
    }

    cout << (solve(h) ? h : l) << '\n';
  };
  
  int tc;
  cin >> tc;
  while (tc--) run_case();
  
  return 0;
}
