#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
template <class T> using vec = vector<T>;

int64_t binpow(int64_t b, int y) {
  int64_t res = 1;
  while (y) {
    if (y & 1) res *= b;
    b = b * b;
    y >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int64_t n; cin >> n;
  int64_t middle = (n - 3) * 9 * binpow(4, n - 3);
  int64_t first_last = 2ll * 3 * binpow(4, n - 2);
  cout << middle + first_last;
  return 0;
}
