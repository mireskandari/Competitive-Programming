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
    vec<string> a(n); for (auto &i : a) cin >> i;
    vec<int> cnt(27);
    for (auto &i : a) {
      for (auto &c : i) {
        cnt[c - 'a']++;
      }
    }
    bool ok = true;
    for (auto &i : cnt) {
      if (i % n != 0) ok = false;
    }
    
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
