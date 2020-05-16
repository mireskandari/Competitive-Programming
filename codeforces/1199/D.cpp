#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define Len(x) (static_cast<int>(x.size()))

/* <not-serious> */
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
    range(T end) : ptt(0, max<T>(0, end)), step(1) {}
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
/* </not-serious> */
int constexpr MOD = 1e9 + 7;
ll constexpr INF = 1e9;


template<class Ch, class Tr, class Container>
basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os, Container const &x) {
    os << "{ ";
    for (auto &y : x) os << y << " ";
    return os << "}";
}

template<class X, class Y>
ostream &operator<<(ostream &os, pair<X, Y> const &p) {
    return os << "[ " << p.first << ", " << p.second << "]";
}

template<class A, class B, class C>
ostream &operator<<(ostream &os, tuple<A, B, C> const &t) {
    return os << "[ " << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << " ]";
}

template<class A, class B, class C, class D>
ostream &operator<<(ostream &os, tuple<A, B, C, D> const &t) {
    return os << "[ " << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ", " << get<3>(t) << " ]";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), t2, x;
    vector<pair<int, int>> com1(n, {-1, -1});
    for (auto i : range(n)) cin >> a[i];
    int q;
    cin >> q;
    for (auto j : range(q)) {
        int s;
        cin >> s;
        if (s == 1) {
            int i, b;
            cin >> i >> b;
            i--;
            com1[i] = {b, j};
        } else {
            int b;
            cin >> b;
            t2.emplace_back(j);
            x.emplace_back(b);
        }
    }
    int t2t = Len(t2);
    vector<int> suf(q + 1);
    suf[q] = -1;
    for (auto i : rrange(q - 1)) {
        if (!binary_search(all(t2), i)) {
            suf[i] = suf[i + 1];
            continue;
        }
        int j = lower_bound(all(t2), i) - t2.begin();
        suf[i] = max(suf[i + 1], x[j]);
    }
    for (auto i : range(n)) {
        if (com1[i].X != -1) {
            a[i] = max(com1[i].X, suf[com1[i].Y]);
        } else {
            a[i] = max(suf[0], a[i]);
        }
        cout << a[i] << ' ';
    }
    return 0;
}