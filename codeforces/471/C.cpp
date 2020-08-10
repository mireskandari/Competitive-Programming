#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  ll cnt = 0;
  for (ll i = 1; i < (int) 1e7; i++) {
    if ((n + i) % 3 == 0) {
      ll r = (n + i) / 3;
      if ((i * (i + 1) / 2) > r) {
        continue;
      }
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}
