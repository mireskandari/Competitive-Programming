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

template <class T = int> using V = vector<T>;
template <class T = int> using VV = V<V<T>>;
template <class T = int> using PP = pair<T, T>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  string s;
  cin >> s;
  int diff = 0;
  int sz = 0;
  for (auto &c : s) {
    if (diff == 0 && c == ')') continue;
    if (c == '(') {
      diff++;
    } else {
      sz++;
      diff--;
    }
  }
  
  cout << 2 * sz;
  return 0;
}
