#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
#define X firidx
#define Y second

using ll = long long; using ld = long double;

template <class T = int> using V = vector<T>;
template <class T = int> using VV = V<V<T>>;
template <class T = int> using PP = pair<T, T>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  V<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  set<int> idx;
  for (int i = 0; i < n; i++) {
    idx.emplace(i);
  }
  V<> another_idx(n);
  iota(all(another_idx), 0);
  sort(all(another_idx), [&](int A, int B) {
    return a[A] < a[B];
  });
  
  ll ans = 0, to_add = 0, to_rem = n;
  for (int i = 0; i < n - 2; i++) {
    if (idx.find(another_idx[i]) == idx.begin() || idx.find(another_idx[i]) == (--idx.end())) {
      ans += (to_rem - 2) * (a[another_idx[i]] - to_add);
      to_add += a[another_idx[i]] - to_add;
    } else {
      ans += min(a[*prev(idx.find(another_idx[i]))], a[*next(idx.find(another_idx[i]))]) - to_add;
    }
    idx.erase(idx.find(another_idx[i]));
    to_rem--;
  }
  
  cout << ans;
  return 0;
}
