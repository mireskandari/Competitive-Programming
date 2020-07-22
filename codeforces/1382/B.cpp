
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
    V<> a(n);
    for (auto &i : a) cin >> i;
    
    V<> dp(n + 1);
    dp[n] = false;
    for (int i = n - 1; i >= 0; i--) {
      dp[i] = !dp[i + 1];
      if (a[i] > 1) dp[i] |= dp[i + 1];
    }
    cout << (dp[0] ? "First" : "Second") << '\n';
  };
  
  int tc;
  cin >> tc;
  while (tc--) {
    run_case();
  }
  return 0;
}
