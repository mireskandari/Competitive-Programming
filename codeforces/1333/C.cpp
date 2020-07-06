#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define cerr if(0) cout
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

#define scream() \
  cerr << "Ah, Here We Go Again!"

template<class Ch, class Tr, class C>
basic_ostream<Ch, Tr>
&operator<<(basic_ostream<Ch, Tr> &os,
            C const v) {
  os << "{ ";
  for (auto i : v) os << i << ' ';
  return os << "}\n";
}

template<class I, class J>
ostream
&operator<<(ostream &os, pair<I, J> p) {
  os << "[ ";
  os << p.first << ' ' ;
  os << p.second << ' ';
  return os << "]\n";
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  V<> a(n);
  for (auto &i : a) cin >> i;
  
  V<ll> pref(n + 1);
  pref[0] = 0;
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + a[i];
  }

  map<ll, int> latest;
  int l = 0;
  ll good = 0;
  for (int i = 0; i <= n; i++) {
    if (latest.find(pref[i]) != latest.end()) {
      l = max(l, latest[pref[i]] + 1);
    }
    good += i - l;
    latest[pref[i]] = i;
  }

  cout << good;
  return 0;
}
