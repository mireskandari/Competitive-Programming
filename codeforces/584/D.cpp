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
  int n;
  cin >> n;
  auto &&pr = [](int a) {
    if (a == 1) return false;
    for (ll i = 2; i * i <= a; i++) {
      if (a % i == 0) {
        return false;
      }
    }
    return true;
  };
  if (pr(n)) {
    cout << 1 << '\n' << n;
    return 0;
  }
  for (int i = n - 2; i >= 2; i--) {
    if (i % 2 != 0 && pr(i)) {
      if (i + 2 == n) {
        cout << 2 << '\n' << i << ' ' << 2;
        return 0;
      }
      if (pr(n - i)) {
        cout << 2 << '\n' << i << ' ' << n - i;
        return 0;
      }
      for (int j = n - i; j >= 2; j--) {
        if (j + i > n) continue;
        if (pr(n - i - j) && pr(j)) {
          cout << 3 << '\n' << i << ' ' << j << ' ' << n - i - j;
          return 0;
        }
      }
    }
  }

  return 0;
}
