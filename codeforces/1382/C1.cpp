
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
template<class I, class J>
using P = pair<I, J>;
template<class T = int>
using PP = P<T, T>;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  auto run_case = []() {
    int n;
    cin >> n;
    string as, bs;
    cin >> as >> bs;
    V<> a(n), b(n);
    for (int i = 0; i < n; i++) {
      a[i] = as[i] == '1';
      b[i] = bs[i] == '1';
    }

    // :)
    V<> ans;
    for (int i = n - 1; i >= 1; i--) {
      if (a[i] == b[i]) continue;
      
      if (a[0] != a[i]) {
        ans.emplace_back(0);
        a[0] = !a[0];
      }
      ans.emplace_back(i);
      reverse(a.begin(), a.begin() + i + 1);
      for (int j = 0; j < i + 1; j++) a[j] = !a[j];
    }
    if (a[0] != b[0]) {
      ans.emplace_back(0);
      a[0] = !a[0];
    }
    
    cout << ans.size() << ' ';
    for (auto &i : ans) cout << i + 1 << ' ';
    cout << '\n';
  };

  int tc;
  cin >> tc;
  while (tc--) {
    run_case();
  }
  return 0;
}
