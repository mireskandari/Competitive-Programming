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

int constexpr N = 2e5 + 10;

int n, a[N];

void solve() {
  cin >> n;

  V<> cnt(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  
  V<> srt(a, a + n);
  sort(all(srt));

  bool good = true;
  for (int i = 0; i < n; i++) {
    if (srt[i] != a[i]) {
      good = false;
      break;
    }
  }

  if (good) {
    cout << "0\n";
    return;
  }

  V<> bad(n + 1);
  for (int i = 0; i < n; i++) {
    if (srt[i] == a[i]) {
      bad[a[i]] = true;
    }
  }

  int from_st = 1;
  for (int i = 0; i < n && a[i] == from_st; from_st++, i++) { 
    bad[a[i]] = false;
  }
  int from_end = n;
  for (int i = n - 1; i >= 0 && a[i] == from_end; i--, from_end--) {
    bad[a[i]] = false;
  }

  cout << (count(all(bad), true) ? 2 : 1) << '\n';
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
