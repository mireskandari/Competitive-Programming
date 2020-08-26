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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // hello
  vector<vector<int>> mn(n, vector<int>(n));
  for (int i = 0; i < n; i++) mn[i][i] = i;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[mn[i][j - 1]]) {
        mn[i][j] = j;
      } else {
        mn[i][j] = mn[i][j - 1];
      }
    }
  }

  // good
  function<ll(int, int, int)> solve = [&](int i, int j, ll mnh) {
    if (j - i < 0) return 0LL;
    if (j - i == 0) return (ll) (a[i] != mnh);
    ll m = a[mn[i][j]];
    ll res = min<ll>(j - i + 1, solve(i, mn[i][j] - 1, m) + solve(mn[i][j] + 1, j, m) + m - mnh);
    return res;
  };
  
  // better
  cout << solve(0, n - 1, 0);
  return 0;
}