#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
template <class T> using vec = vector<T>;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vec<int64_t> a(n); for (auto &i : a) cin >> i;
  if (n == 1) {
    for (int i = 0; i < 2; ++i) cout << 1 << ' ' << 1 << '\n' << 0 << '\n';
    cout << 1 << ' ' << 1 << '\n' << -a[0];
    exit(0);
  }

  cout << 1 << ' ' << n << '\n';
  for (int i = 0; i < n; ++i) {
    int64_t rm = a[i] % (n - 1) + (n - 1);
    rm %= n - 1;
    int64_t delta = (n - 1 - rm) * n;
    a[i] += delta;
    cout << delta << ' ';
  }
  
  cout << '\n';
  cout << 1 << ' ' << 1 << '\n' << -a[0] << '\n';
  a[0] = 0;
  cout << 2 << ' ' << n << '\n';
  for (int i = 1; i < n; ++i) {
    cout << -a[i] << ' ';
  }

  return 0;
}
