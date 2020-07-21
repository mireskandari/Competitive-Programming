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


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, t;
  cin >> n >> t;
  string s1, s2;
  cin >> s1 >> s2;
  
  int eq = 0, neq = 0;
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i]) neq++;
    else eq++;
  }
  
  int eqq = n - t;
  if (neq < 2 * (eqq - eq)) {
    cout << -1;
    return 0;
  }

  set<char> fr;
  for (int c = 'a'; c <= 'z'; c++) {
    fr.emplace(c);
  }
  
  string ans(n, '0');
  for (int i = 0; i < n && eqq; i++) {
    if (s1[i] == s2[i]) {
      ans[i] = s1[i];
      eqq--;
    }
  }
  
  int tmp = 2 * eqq;
  for (int i = 0; i < n && tmp; i++) {
    if (s1[i] == s2[i]) continue;
    tmp--;
    ans[i] = (tmp & 1 ? s1[i] : s2[i]);
  }
  
  for (int i = 0; i < n; i++) {
    if (ans[i] == '0') {
      fr.erase(s1[i]);
      fr.erase(s2[i]);
      ans[i] = *fr.begin();
      fr.emplace(s1[i]);
      fr.emplace(s2[i]);

    }
  }

  cout << ans;
  return 0;
}
