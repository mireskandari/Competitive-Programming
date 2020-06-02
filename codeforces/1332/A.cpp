#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

typedef long long ll;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define X first
#define Y second

/* <not-serious> */
template<typename T>
struct num_it : iterator<forward_iterator_tag, T> {
    T v, step;
    num_it(T _v) : v(_v), step(1) {}
    num_it(T _v, T _step) : v(_v), step(_step) {}
    operator T &() { return v; }
    T operator*() const { return v; }
    num_it operator++() { v += step; return *this; }
    bool operator!=(num_it rhs) {
        return step > 0 ? v < rhs.v : v > rhs.v;
    }
};

template<typename T = int>
struct range : pair<T, T> {
    T step;
    using ptt = pair<T, T>;
    range(T end) : ptt(0, max<T>(0, end)), step(1) {}
    range(T begin, T end, T _step = 1) :
    ptt(begin, _step > 0 ? max(begin, end) : min(begin, end - 1)),
    step(_step) {}
    num_it<T> begin() const {
        return num_it<T>(this->first, step);
    }
    num_it<T> end() const {
        return num_it<T>(this->second, step);
    }
};

template<typename T = int>
struct rrange : range<T> {
    rrange(T end, T begin, T step = 1) :
    range<T>(end, begin, -step) {}
    rrange(T end) : range<T>(end, 0, -1) {}
};

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

template<typename T>
inline int constexpr size(T &cont) {
    return cont.size();
}
/* </not-serious> */



ll constexpr INF = 1e18;

void run_case() {
    int a, b, c, d;
    int x, y, x1, y1, x2, y2;
    cin >> a >> b >> c >> d;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    bool ok = true;
    if (a > 0 || b > 0) {
        if (x1 == x2) ok = false;
    }
    if (c > 0 || d > 0) {
        if (y1 == y2) ok = false;
    }
    int mx = min(a, b);
    a -= mx;
    b -= mx;
    int my = min(c, d);
    c -= my;
    d -= my;
    ok &= (x1 <= x - a + b && x - a + b <= x2 && y1 <= y - c + d && y - c + d <= y2);
    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        run_case();
    }
    return 0;
}