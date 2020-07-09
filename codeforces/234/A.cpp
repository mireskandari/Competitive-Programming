#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#endif

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
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  
  bool odd = (n / 2) & 1;

  if ((n / 2) & 1) {
    if(s[0] == s.back()) {
      cout << 1 << ' ' << n << '\n';
    } else {
      if (s[0] == 'L') {
        cout << 1 << ' ' << n << '\n';
      } else {
        cout << n << ' ' << 1 << '\n';
      }
    }
    n -= 2;
    string(1 + all(s) - 1).swap(s);
  }
  
  VV<PP<>> gp(2);
  for (int i = 0; i < n; i++) {
    gp[i % 2].emplace_back(s[i], i);
  }
  
  sort(all(gp[0]));
  sort(all(gp[1]));

  for (int g = 0; g < 2; g++) {
    for (int i = 0; i < (int) gp[g].size() - 1; i += 2) {
      if (gp[g][i + 1].X == gp[g][i].X) {
        cout << gp[g][i].Y + 1 + odd << ' ' << gp[g][i + 1].Y + 1 + odd << '\n';
      } else {
        int f = gp[g][i].Y, s = gp[g][i + 1].Y;
        if (gp[g][i].X == 'R') swap(f, s);
        cout << f + 1 + odd << ' ' << s + 1 + odd << '\n';
      }
    }
  }
  return 0;
}
  
