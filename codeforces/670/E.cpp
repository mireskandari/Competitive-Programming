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

struct node {
  int l, r;
  char c;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  //some manual linked list :/
  int constexpr N = 3e6;
  V<node> ls(N + 10);
  for (int i = 0; i <= N + 2; i++) {
    ls[i].l = i - 1;
    ls[i].r = i + 1;
  }
  
  int n, m, p;
  cin >> n >> m >> p;
  string s;
  cin >> s;
  for (int i = 1; i <= n; i++) {
    ls[i].c = s[i - 1];
  }
  
  stack<int> st;
  V<> match(n);
  for (int i = 0; i < n; i++) {
    if (!st.empty() && s[st.top()] != s[i]) {
      match[i] = st.top();
      match[st.top()] = i;
      st.pop();
    } else {
      st.push(i);
    }
  }
  
  
  while (m--) {
    char command;
    cin >> command;
    
    if (command == 'R') {
      p = ls[p].r;
    } else if (command == 'L') {
      p = ls[p].l;
    } else {
      int left, right;
      if (match[p - 1] + 1 > p) {
        left = ls[p].l;
        right = ls[match[p - 1] + 1].r;
      } else {
        left = ls[match[p - 1] + 1].l;
        right = ls[p].r;
      }
      
      ls[left].r = right;
      ls[right].l = left;
      if (right > n) p = left;
      else p = right;
    }
  }
  
  for (int i = ls[0].r; i <= n; i = ls[i].r) {
    cout << ls[i].c;
  }
  
  return 0;
}
