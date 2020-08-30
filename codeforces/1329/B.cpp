#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
template <class T> using vec = vector<T>;

int MOD;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int tc; cin >> tc;
  while (tc--) {
    int d; cin >> d >> MOD;
    int64_t cnt = 1;
    while (d > 1) {
      int msb = 31 - __builtin_clz(d);
      int less_pw2 = (1 << msb) - 1;
      cnt *= d - less_pw2 + 1;
      cnt %= MOD;
      d = less_pw2;
    }
    cnt = cnt * 2 % MOD;
    cout << (cnt + MOD - 1) % MOD << '\n';
  }
  return 0;
}
