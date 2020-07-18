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

int n;
string s;

inline int solve(int l, int r, char c) {
  if (r - l == 0) return 0;
  if (r - l == 1) return (s[l] != c);
  
  int m = (1LL * l + 1LL * r) >> 1LL;
  int side1 = count(s.begin() + l, s.begin() + m, c);
  int side2 = count(s.begin() + m, s.begin() + r, c);
  return min(m - l - side1 + solve(m, r, c + 1), r - m - side2 + solve(l, m, c + 1));
}

inline void run_case() {
  cin >> n >> s;
  cout << solve(0, n, 'a') << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    run_case();
  }
  return 0;
}
