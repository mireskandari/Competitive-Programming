#include <bits/stdc++.h>
using namespace std;

#ifndef LOCAL
#define cerr if(0) cerr
#endif

#define EB(a) emplace_back(a)
#define MP(a, b) make_pair(a, b)
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  using tp = tuple<int, int, int>;
  auto cmp = [](tp a, tp b) {
    if (get<0>(a) != get<0>(b)) {
      return get<0>(a) > get<0>(b);
    } else if (get<1>(a) != get<1>(b)) {
      return get<1>(a) < get<1>(b);
    }
    return get<2>(a) < get<2>(b);
  };
  vector<tp> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> get<1>(a[i]) >> get<0>(a[i]);
    get<2>(a[i]) = i;
  }
  sort(a.begin(), a.end(), cmp);
  int k;
  cin >> k;
  set<pair<int, int>> st;
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    st.emplace(x, i);
  }
  int used = 0, money = 0, ptr = 0;
  vector<int> place(n, -1);
  while (ptr < n) {
    int mon, cnt, i;
    tie(mon, cnt, i) = a[ptr];
    ptr++;
    auto it = st.lower_bound(MP(cnt, -INT_MAX));
    if (it == st.end()) continue;
    ++used; money += mon;
    place[i] = it->second;
    st.erase(it);
  }
  cout << used << ' ' << money << '\n';
  for (int i = 0; i < n; ++i) {
    if (place[i] > -1) {
      cout << i + 1 << ' ' << place[i] + 1 << '\n';
    }
  }
  return 0;
}

