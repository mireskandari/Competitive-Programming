#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define X first
#define Y second

/* <not-serious> */
template<typename T>
struct number_iterator : iterator<forward_iterator_tag, T> {
    T v, step;

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
};

template<typename T = int>
struct range : pair<T, T> {
    T step;

    T _end(T begin, T end, T _step) {
        return _step > 0 ? max(begin, end) : min(begin, end - 1);
    }

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
};

template<typename T = int>
struct rrange : range<T> {
    rrange(T end, T begin) : range<T>(end, begin, -1) {}

    rrange(T end) : range<T>(end, 0, -1) {}
};

#if __cplusplus >= 201703L

template<class T = int, class... Args>
auto vec(size_t n, Args &&... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, T(args...));
    else
        return vector(n, vec<T>(args...));
}

#else
template<int D, typename T>
struct vec : public vector<vec<D - 1, T>> {
    template<typename... Args>
    vec(int n = 0, Args... args) :
    vector<vec<D - 1, T>>(n, vec <D - 1, T>(args...)) {}
};

template<typename T>
struct vec<1, T> : public vector<T> {
    vec(int n = 0, const T &val = T()) :
    vector<T>(n, val) {}
};
#endif

template<typename T>
inline int constexpr size(T &cont) {
    return cont.size();
}

/* </not-serious> */



ll constexpr INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto i : range(n)) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    sort(all(a));
    ll cnt = 0;
    for (auto i : range(n)) {
        int p1 = upper_bound(all(a), a[i] * 2) - a.begin() - 1;
        cnt += p1 - i;
    }
    cout << cnt;
    return 0;
}