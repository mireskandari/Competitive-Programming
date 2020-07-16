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

void run_case() {
  int n;
  cin >> n;
  if (!(n & 1)) {
    cout << n / 2 << ' ' << n / 2 << '\n';
    return;
  }
  
  ll small;
  for (small = 3; small * small <= n; small++) {
    if (n % small == 0) {
      break;
    }
  }
  if (n % small != 0) small = n;

  cout << n / small << ' ' << n - n / small << '\n';
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
