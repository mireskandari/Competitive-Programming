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
  //  ios::sync_with_stdio(false);
  //  cin.tie(nullptr);
  
  int n, k;
  scanf("%d %d", &n, &k);
  V<> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  
  set<int> st;
  map<int, int> mp;
  for (int i = 0; i < k; i++) {
    mp[a[i]]++;
  }
  for (auto &p : mp) {
    if (p.Y == 1) st.emplace(p.X);
  }
  
  auto pr = [&]() {
    string s = (st.empty() ? "Nothing" : to_string(*(--st.end())));
    printf("%s \n", s.c_str());
  };
  
  pr();
  for (int i = k; i < n; i++) {
    mp[a[i - k]]--;
    if (mp[a[i - k]] == 0) {
      st.erase(a[i - k]);
    }
    if (mp[a[i - k]] == 1) {
      st.emplace(a[i - k]);
    }
    
    mp[a[i]]++;
    if (mp[a[i]] > 1) st.erase(a[i]);
    if (mp[a[i]] == 1) {
      st.emplace(a[i]);
    }
    
    pr();
  }
  return 0;
}
