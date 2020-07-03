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
	int n;
	cin >> n;
	vector<ll> a(n);
	for (auto &i : a) cin >> i;
	string s;
	cin >> s;
	
	reverse(all(s));
	reverse(all(a));

	vector<ll> suf(n + 1), pref(n);
	suf[n - 1] = a[n - 1];
	pref[0] = (s[0] == '1' ? a[0] : 0);
	for (auto i : rrange<>(n - 2)) suf[i] = suf[i + 1] + a[i];
	for (auto i : range<>(1, n)) {
		pref[i] = pref[i - 1];
		if (s[i] == '1') pref[i] += a[i];
	}

	vector<int> one;
	for (auto i : range<>(n)) {
		if (s[i] == '1') one.emplace_back(i);
	}
	
	ll ans = 0;
	for (auto &i : one) {
		ans = max(ans, (i != 0 ? pref[i - 1] : 0) + suf[i + 1]);
	}
	ll ans2 = 0;
	for (auto i : range<>(n)) {
		if (s[i] == '1') ans2 += a[i];
	}
	ans = max(ans2, ans);

	cout << ans;
	return 0;
}
