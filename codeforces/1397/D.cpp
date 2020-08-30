#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
template <class T> using vec = vector<T>;

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    vec<int> a(n); for (auto &i : a) cin >> i;
    multiset<int> st;
    for (auto &i : a) st.emplace(i);
    
    int removed = -1;
    bool who = true;
    while (!st.empty()) {
      int new_removed = *st.rbegin() - 1;
      if (!new_removed) new_removed = -1;
      st.erase(prev(st.end()));
      if (removed != -1) {
        st.emplace(removed);
      }
      swap(removed, new_removed);
      who = !who;
    }

    cout << (!who ? "T" : "HL") << '\n';
  }
  return 0;
}
