#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
template <class T> using vec = vector<T>;
using vll = vec<int64_t>; using vii = vec<int>;


int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int n; cin >> n;
  vii a(n); for (auto &i : a) cin >> i;
  
  rotate(a.begin(), max_element(all(a)), a.end());
  ++a[0];
  a.emplace_back(a[0]);
  
  // tired of stacks
  vii l(n + 3, -1), r(n + 3, n + 2);
  for (int i = 1; i < n + 1; ++i) {
    int option = i - 1;
    while (option >= 0 && a[option] <= a[i]) {
      option = l[option];
    }
    l[i] = option;
  }
  for (int i = n; i >= 0; --i) {
    int option = i + 1;
    while (option < n + 1 && a[option] <= a[i]) {
      option = r[option];
    }
    r[i] = option;
  }

  // the boss bitch
  vll fen(n + 4);
  auto update = [&](int idx, int64_t v) {
    for (++idx; idx < n + 4; idx += idx & -idx) {
      fen[idx] += v;
    }
  };
  auto sum = [&](int idx) {
    int64_t res = 0;
    for (++idx; idx > 0; idx -= idx & -idx) {
      res += fen[idx];
    }
    return res;
  };

  int64_t cnt = 0;
  vec<vii> bl(n + 4);
  update(r[0], 1);
  for (int i = 1; i < n + 1; ++i) {
    cnt += sum(n + 2) - sum(i - 1);
    update(r[i], 1);
    if (l[i] > 0) bl[l[i] - 1].emplace_back(i - 1);
  }
  
  fill(all(fen), 0);
  for (int i = 0; i < n + 1; ++i) {
    update(r[i], 1);
    for (auto &j : bl[i]) {
      cnt -= sum(n + 2) - sum(j);
    }
  }

  for (int i = 0; i < n + 1; ++i) {
    if (l[i] == 0 && r[i] == n) --cnt;
  }
  --cnt;

  cout << cnt;
  return 0;
}
