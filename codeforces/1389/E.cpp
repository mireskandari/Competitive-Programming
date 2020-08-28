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
    int64_t m, d, w; cin >> m >> d >> w;
    auto calc = [](int64_t A) {
      return (A * (A - 1)) / 2;
    };
    int64_t ww = w / __gcd(d - 1, w);
    int64_t a = min(m, d);
    int64_t rm = a % ww;
    cout << calc(a / ww) * (ww - rm) + calc(a / ww + 1) * rm << '\n';
  }
  return 0;
}
