#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

typedef long long ll;

int constexpr N = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int r, g, w, b;
    cin >> r >> g >> b >> w;
    int cnt = (r % 2 == 0) + (b % 2 == 0) + (g % 2 == 0) + (w % 2 == 0);
    if (cnt >= 3 || (r > 0 && g > 0 && b > 0 && (cnt <= 1))) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
