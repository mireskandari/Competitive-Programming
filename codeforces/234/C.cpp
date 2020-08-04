#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define cerr if(0) cerr
#endif

typedef long long ll;
#define V(T) vector<T>
#define PP(T) pair<T, T>

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  V(int) a(n);
  for (auto &i : a) cin >> i;
  int l = 0, r = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) continue;
    r++;
  }
  int best = INT_MAX;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] >= 0) l++;
    if (a[i] <= 0) r--;
    best = min(best, l + r);
  }

  cout << best;
  return 0;
}
