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
  vector<int> cnt(10);
  multiset<int> st;
  for (int i = 0; i < 6; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  for (int i = 0; i < 10; i++) {
    st.emplace(cnt[i]);
  }
  auto p = st.rbegin();
  auto p1 = next(p);
  auto p2 = next(p1);
  auto no = []() { cout << "Alien"; };
  auto el = []() { cout << "Elephant"; };
  auto be = []() { cout << "Bear"; };
  if (*p < 4) {
    no();
  } else if (*p >= 6 || *p1 >= 2) {
    el();
  } else if ((*p1 > 0 && *p2 > 0) || (*p1 > 0 && *p >= 5)) {
    be();
  } else {
    no();
  }
  return 0;
}
