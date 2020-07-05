#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define cerr if(0) cout
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
  
  auto &&run_case = [&]() {
    int n;
    cin >> n;
    V<> a(n);
    for (auto &i : a) cin >> i;

    int sign = 0;
    for (auto &i : a) {
      if (sign && i > 0) i = -i;
      if (!sign && i < 0) i = -i;
      sign ^= 1;
      cout << i << ' ';
    }
    cout << '\n';
  };
  
  int tc;
  cin >> tc;
  while (tc--) run_case();
  return 0;
}
