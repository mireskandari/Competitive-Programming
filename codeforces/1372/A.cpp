#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
#define X first
#define Y second

using ll = long long;

template <class T = int> using V = vector<T>;
template <class T = int> using VV = V<V<T>>;
template <class T = int> using PP = pair<T, T>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cout << 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}
