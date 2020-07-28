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
template<class T = int>
using PP = pair<T, T>;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = (int) s.size();
  
  V<> pref(n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + (s[i - 1] == '(' ? 1 : -1);
  }
  
  V<> l(n + 1);
  stack<int> st;
  for (int i = 0; i <= n; i++) {
    while (!st.empty() && pref[st.top()] >= pref[i]) {
      st.pop();
    }
    l[i] = (st.empty() ? 0 : st.top() + 1);
    st.push(i);
  }
  
  map<int, V<>> pos;
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == '(') pos[pref[i] - 1].emplace_back(i);
  }
  
  for (int i = 1; i <= n; i++) {
    auto p = lower_bound(all(pos[pref[i]]), l[i]);
    if (s[i - 1] != '(') {
      l[i] = (p == pos[pref[i]].end() || *p > i ? -10 : *p);
    } else {
      l[i] = -10;
    }
  }
  
  bool found = false;
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == ')' && l[i] != -10) {
      found = true;
      break;
    }
  }
  if (!found) {
    cout << "0 1";
    return 0;
  }
      
  map<int, int> len;
  for (int i = 1; i <= n; i++) {
    if (l[i] != -10) {
      len[i - l[i] + 1]++;
    }
  }
  
  cout << len.rbegin()->X << ' ' << len.rbegin()->Y;
  return 0;
}
