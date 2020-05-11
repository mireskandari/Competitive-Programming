#include <bits/stdc++.h>

using namespace std;
// <some useless shit>
typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define Len(x) (static_cast<int>(x.size()))

template<typename T>
class number_iterator : iterator<forward_iterator_tag, T> {
public:
    number_iterator(T _v) : v(_v), step(1) {}
    number_iterator(T _v, T _step) : v(_v), step(_step) {}
    operator T &() { return v; }
    T operator*() const { return v; }
    number_iterator operator++() {
        v += step;
        return *this;
    }
    bool operator!=(number_iterator rhs) {
        return step > 0 ? v < rhs.v : v > rhs.v;
    }
private:
    T v, step;
};

template<typename T = int>
class range : pair<T, T> {
public:
    using ptt = pair<T, T>;
    range(T begin, T end) : ptt(begin, max(begin, end)), step(1) {}
    range(T end) :
            ptt(static_cast<T>(0), max(static_cast<T>(0), end)), step(1) {}
    range(T begin, T end, T _step) :
            ptt(begin, _end(begin, end, _step)), step(_step) {}
    number_iterator<T> begin() const {
        return number_iterator<T>(this->first, step);
    }
    number_iterator<T> end() const {
        return number_iterator<T>(this->second, step);
    }
private:
    T step;
    T _end(T begin, T end, T _step) {
        return _step > 0 ? max(begin, end) : min(begin, end - 1);
    }
};

template<typename T = int>
class rrange : public range<T> {
public:
    rrange(T end, T begin) : range<T>(end, begin, -1) {}
    rrange(T end) : range<T>(end, 0, -1) {}
};

template<class T = int, class... Args>
auto vec(size_t n, Args &&... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, T(args...));
    else
        return vector(n, vec<T>(args...));
}
// </some useless shit>
int constexpr MOD = 1e9 + 7;
ll constexpr INF = 1e9;


template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) {
    os << "{ ";
    for(auto& y : x) os << y << " ";
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) {
    return os << "[ " << p.first << ", " << p.second << "]" ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    auto Solve = []() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto i : range(n)) cin >> a[i];
        vector<int> l(n), r(n), psl(n + 2, true), psr(n + 2, true);
        for (auto i : range(n)) {
            l[i] = a[i] >= i;
            psl[i + 1] = psl[i] && l[i];
            int j = n - i - 1;
            r[j] = a[j] >= i;
            psr[j + 1] = psr[j + 2] && r[j];
        }
//        cout << r << ' ' << l << ' ' << psl << ' ' << psr << '\n';
        for (auto i : range(n)) {
            if (a[i] > i - 1 && a[i] > n - i - 2 && psl[i] && psr[i + 2]) {
                cout << "YES\n";
                return 0;
            }
        }
        cout << "NO\n";
        return 0;
    };
    while (tc--) {
        Solve();
    }
    return 0;
}