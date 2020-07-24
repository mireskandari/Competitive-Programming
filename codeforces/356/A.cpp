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
template<class T = int>
using PP = pair<T, T>;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, m;
  cin >> n >> m;
  set<int> st;
  for (int i = 1; i <= n; i++) {
    st.emplace(i);
  }
  
  V<> dead_by(n + 1);
  while (m--) {
    int a, b, x;
    cin >> a >> b >> x;
    dead_by[x] = 0;
    auto en = st.upper_bound(b);
    V<> to_erase;
    for (auto it = st.lower_bound(a); it != en; it++) {
      if (*it == x) continue;
      dead_by[*it] = x;
      to_erase.emplace_back(*it);
    }
    for (auto &i : to_erase) st.erase(i);
  }
  
  for (int i = 1; i <= n; i++) {
    cout << dead_by[i] << ' ';
  }
  return 0;
}
