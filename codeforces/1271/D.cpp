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
ll constexpr INF = 1e8;

#define int long long
int const N = 5000, K = 5000;
int dp[N + 1][K + 1];
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    auto g = new vector<int>[n];
    auto last = new vector<int>[n];
    vector<int> a(n), b(n), c(n);
    for (auto i : range(n)) cin >> a[i] >> b[i] >> c[i];
    for (auto i : range(m)) {
        int v, u;
        cin >> v >> u;
        g[--u].emplace_back(--v);
    }
    for (auto i : range(n)) {
        g[i].emplace_back(i);
        last[*max_element(all(g[i]))].emplace_back(i);
    }
    for (auto i : range(n)) {
        sort(all(last[i]), [&c](int a, int b) { return c[a] > c[b]; });
    }
    for (auto i : rrange(n - 1)) {
        for (auto j : range(5001)) {
            dp[i][j] = -INF;
            if (j < a[i]) continue;
            ll sum = 0;
            dp[i][j] = dp[i + 1][j + b[i]];
            for (auto x : range(Len(last[i]))) {
                sum += c[last[i][x]];
                int nw = j - x - 1 + b[i];
                if (nw <= 5000 && nw >= 0) {
                    dp[i][j] = max<ll>(dp[i][j], dp[i + 1][nw] + sum);
                }
            }
        }
    }
    cout << (dp[0][k] < 0 ? -1 : dp[0][k]);
    return 0;
}