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
    
    ll l, r;
    cin >> l >> r;
    if (r & 1) r--;
    if (l == r) {
      cout << -1 << ' ' << -1 << '\n';
    } else if (r / 2 >= l) {
      cout << r / 2 << ' ' << r << '\n';
    } else {
      cout << -1 << ' ' << -1 << '\n';
    }
  }
  return 0;
}
