#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define cerr if(0) cout
#endif

using ll = long long;
using ld = long double;

#define all(v) (v).begin(), (v).end()
#define X first
#define Y second

// magic
template<class T> struct Nit { T _v, _s; Nit(T v, T s) : _v(v), _s(s) {} operator T &() { return _v; } T operator *() const { return _v; } Nit &operator++() { _v += _s; return *this; } bool operator!=(Nit &a) { return (_s > 0 ? _v < a._v : _v >= a._v); } }; template<class T = int> struct range { T _b, _e, _s; range(T e) : _b(0), _e(e), _s(1) {} range(T b, T e, T s = 1) : _b(b), _e(e), _s(s) {} Nit<T> begin() { return Nit<T>(_b, _s); } Nit<T> end() { return Nit<T>(_e, _s); } }; template<class T = int> struct rrange : range<T> { rrange(T e, T b, T s = 1) : range<T>(e, b, -s) {} rrange(T e) : range<T>(e, 0, -1) {} };  template<int D, class T> struct vec : public vector<vec<D - 1, T>> { template<class... Args> vec(int n = 0, Args... a) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(a...)) {} }; template<class T> struct vec<1, T> : public vector<T> { vec(int n = 0, T const &val = T()) : vector<T>(n, val) {} }; template<int N, class T> void print_tuple(ostream &, T const &) {} template<int N, class T, class H, class... Args> void print_tuple(ostream &os, T const &t) { if (N) os << " ,"; os << std::get<N>(t); print_tuple<N + 1, T, Args...>(os, t); } template<class... Args> ostream &operator<<(ostream &os,const tuple<Args...> &t){ os << "{"; print_tuple<0, tuple<Args...>, Args...>(os, t); return os << "}"; } template<class Ch, class Tr, class C> basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os, C const &x) { os << "{ "; for (auto &y : x) os << y << " "; return os << "}"; } template<class I, class J> ostream &operator<<(ostream &os, pair<I, J> const &p) { return os << "[ " << p.first << ", " << p.second << " ]"; }

// now start
ll constexpr INF = 1e14;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (auto &i : a) cin >> i;
  
  int const dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
  auto &&check = [&](int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
  };

  vec<2, char> mark(n, m, false);
  vec<2, int> ceach(n, m);

  function<void(int, int, int, int &)> dfs = [&](int vx, int vy, int c, int &com) {
    mark[vx][vy] = true;
    ceach[vx][vy] = c;
    com++;

    for (auto i : range<>(4)) {
      int nx = vx + dx[i], ny = vy + dy[i];
      if (check(nx, ny) && a[nx][ny] == '.' && !mark[nx][ny]) {
        dfs(nx, ny, c, com);
      }
    }
  };
  
  vector<int> comp;
  for (auto i : range<>(n)) {
    for (auto j : range<>(m)) {
      if (a[i][j] == '.' && !mark[i][j]) {
        comp.emplace_back(0);
        dfs(i, j, (int) comp.size() - 1, comp.back());
      }
    }
  }
  cerr << comp << '\n';
  vec<2, int> ans(n, m);

  for (auto i : range<>(n)) {
    for (auto j : range<>(m)) {
      if (a[i][j] == '*') {
        set<int> adjc;
        for (auto x : range<>(4)) {
          int nx = i + dx[x], ny = j + dy[x];
          if (check(nx, ny) && a[nx][ny] == '.') adjc.emplace(ceach[nx][ny]);
        }
        cerr << i << ' ' << j << ' ' << adjc << '\n';
        int sz = 0;
        for (auto &x : adjc) sz += comp[x];
        ans[i][j] = sz;
      }
    }
  }

  for (auto i : range<>(n)) {
    for (auto j : range<>(m)) {
      if (a[i][j] == '.') cout << '.';
      else cout << (ans[i][j] + 1) % 10;
    }
    cout << '\n';
  }
  return 0;
}

