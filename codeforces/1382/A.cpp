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
    int n, m;
    cin >> n >> m;
    V<> mark1(2e5, false), mark2(2e5, false);
    V<> a(n), b(m);
    for (auto &i : a) {
      cin >> i;
      mark1[i] = true;
    }
    for (auto &i : b) {
      cin >> i;
      mark2[i] = true;
    }
    for (int i = 0; i < (int) 2e5; i++) {
      if (mark1[i] && mark2[i]) {
        cout << "YES\n1 " << i << '\n';
        return;
      }
    }
    cout << "NO\n";
  };
  
  int tc;
  cin >> tc;
  while (tc--) {
    run_case();
  }
  return 0;
}

