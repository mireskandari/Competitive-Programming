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

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class T, class Comp = less<T>>
using pbds = tree<T, null_type, Comp, rb_tree_tag, tree_order_statistics_node_update>;
// why merge sort when you have this

int n;
V<> a, pos;
map<int, int> id;
pbds<int> s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    int id1 = (id.find(a) != id.end() ? id[a] : a);
    int id2 = (id.find(b) != id.end() ? id[b] : b);
    id[a] = id2;
    id[b] = id1;
    // cerr << id[a] << ' ' << id[b] << '\n';
  }
  
  cerr << "\n\n\n";

  for (auto &p : id) {
    a.emplace_back(p.Y);
    pos.emplace_back(p.X);
    cerr << a.back() << ' ' << pos.back() << '\n';
  }
  
  ll inv = 0;
  for (int i = 0; i < (int) a.size(); i++) {
    inv += s.order_of_key(-a[i]);
    s.insert(-a[i]);
    
    if (pos[i] < a[i]) {
      ll en = lower_bound(all(pos), a[i]) - pos.begin();
      ll unchanged = a[i] - pos[i];
      inv += unchanged - (en - i);
    } else {
      ll st = lower_bound(all(pos), a[i]) - pos.begin();
      ll unchanged = pos[i] - a[i];
      cerr << st << ' ' << unchanged << ' ' << i - st << '\n';
      inv += unchanged - (i - st);
    }
  }

  cout << inv;
  return 0;
}
