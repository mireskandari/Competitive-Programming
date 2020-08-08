#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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
  vector<int> cnt((int) 1e5 + 10);
  multiset<int> st;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  for (int i = 0; i < (int) cnt.size(); i++) {
    st.emplace(cnt[i]);
  }
  int q;
  cin >> q;
  while (q--) {
    char command;
    cin >> command;
    int x;
    cin >> x;
    st.erase(st.find(cnt[x]));
    if (command == '-') {
      cnt[x]--;
    } else {
      cnt[x]++;
    }
    st.emplace(cnt[x]);
    auto p1 = st.rbegin();
    auto p2 = next(p1);
    auto p3 = next(p2);
    int const val[] = {*p1, *p2, *p3};
    if (val[0] >= 8 || (val[0] >= 6 && val[1] >= 2) ||
        (val[0] >= 4 && val[1] >= 4) || (val[0] >= 4 && val[1] >= 2 && val[2] >= 2)) {

      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
