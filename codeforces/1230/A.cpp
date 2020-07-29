#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define all(v) (v).begin(), (v).end()
#define X first
#define Y second

using ll = long long; using ld = long double;

template <class T = int> using V = vector<T>;
template <class T = int> using VV = V<V<T>>;
template <class T = int> using PP = pair<T, T>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  V<> a(4);
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
  }
  sort(all(a));

  do {
    int sum1 = 0, sum2 = a[0] + a[1] + a[2] + a[3];
    if (sum1 == sum2) {
      cout << "YES";
      return 0;
    }
    for (int i = 0; i < 4; i++) {
      sum1 += a[i];
      sum2 -= a[i];
      if (sum1 == sum2) {
        cout << "YES";
        return 0;
      }
    }
  } while (next_permutation(all(a)));
  
  cout << "NO";
  return 0;
}
