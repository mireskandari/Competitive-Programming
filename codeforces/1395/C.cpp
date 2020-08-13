// ridam.
#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

typedef long long ll;

int constexpr N = 300;

int n, m;
int a[N], b[N];
bool dp[N][1 << 10];
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  dp[0][0] = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int mask = 0; mask <= (1 << 9); ++mask) {
        dp[i + 1][mask | (a[i] & b[j])] |= dp[i][mask];
      }
    }
  }
  for (int mask = 0; mask <= (1 << 9); ++mask) {
    if (dp[n][mask]) {
      cout << mask;
      return 0;
    }
  }
  return 0;
}
