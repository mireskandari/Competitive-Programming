#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define X first
#define Y second

/* <not-serious> */
template<typename T>
struct number_iterator :
            iterator<forward_iterator_tag, T> {
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
        return _step > 0 ? max(begin, end) :
                           min(begin, end - 1);
    }
    using ptt = pair<T, T>;
    range(T begin, T end) : ptt(begin, max(begin, end)),
                            step(1) {}
    range(T end) : ptt(0, max<T>(0, end)), step(1) {}
    range(T begin, T end, T _step) :
            ptt(begin, _end(begin, end, _step)),
            step(_step) {}
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

void run_case() {
    int n;
    cin >> n;
    auto pos = vec(201, 0, 0);
    auto lb = vec(201, n, 0);
    for (auto i : range(n)) {
        int a;
        cin >> a;
        pos[a].emplace_back(i);
    }

    int mx = 0;
    for (auto i : range(201)) {
        for (auto j : range(size(pos[i]) / 2)) {
            int match_size = 2 * j + 2;
            int best_mid = 0;
            for (auto x : range(201)) {
                if (i == x) continue;
                int mid = lower_bound(all(pos[x]), pos[i][size(pos[i]) - j - 1]) -
                        lower_bound(all(pos[x]), pos[i][j]);
                best_mid = max(best_mid, mid);
            }
            mx = max(mx, match_size + best_mid);
        }
    }
    for (auto i : range(201)) {
        mx = max(mx, size(pos[i]));
    }
    cout << mx << '\n';
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