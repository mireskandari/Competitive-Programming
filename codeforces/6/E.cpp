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
  
  int n, k;
  cin >> n >> k;
  V<> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  V<> l(n);
  multiset<int> st = {a[0]};
  
  auto check = [&]() {
    return *st.rbegin() - *st.begin() > k;
  };
  
  l[0] = 0;
  for (int i = 1; i < n; i++) {
    st.emplace(a[i]);
    int j = l[i - 1];
    while (*st.rbegin() - *st.begin() > k) {
      st.erase(st.find(a[j]));
      j++;
    }
    l[i] = j;
  }
  
  int sz = INT_MIN;
  for (int i = 0; i < n; i++) {
    sz = max(sz, i - l[i] + 1);
  }
  
  multiset<int>().swap(st);
  
  V<> ans;
  for (int i = 0; i < sz; i++) {
    st.emplace(a[i]);
  }
  if (!check()) ans.emplace_back(sz - 1);
  
  for (int i = sz; i < n; i++) {
    st.emplace(a[i]);
    st.erase(st.find(a[i - sz]));
    if (!check()) ans.emplace_back(i);
  }
  
  cout << sz << ' ' << ans.size() << '\n';
  for (auto &i : ans) cout << i - sz + 2 << ' ' << i + 1 << '\n';
  return 0;
}
