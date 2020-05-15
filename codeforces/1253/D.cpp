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


using pii = pair<int, int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    auto g = vec(n, 0, 0);
    for (auto i : range(m)) {
        int v, u;
        cin >> v >> u;
        g[--v].emplace_back(--u);
        g[u].emplace_back(v);
    }
    vector<char> mark(n, false);
    auto Dfs = [&](auto& F, int v, int& mn, int& mx) -> void {
        mark[v] = true;
        mn = min(v, mn);
        mx = max(mx, v);
        for (auto u : g[v]) {
            if (!mark[u]) F(F, u, mn, mx);
        }
    };
    vector<pii> comp;
    for (auto i : range(n)) {
        if (!mark[i]) {
            int mn = INF, mx = -INF;
            Dfs(Dfs, i, mn, mx);
            comp.emplace_back(mn, mx);
        }
    }
    set<pii> cmp(all(comp));
    if (Len(cmp) == 1) return cout << 0, 0;
    auto i = cmp.begin();
    int cnt = 0;
    while (Len(cmp) > 1) {
        auto j = i;
        j++;
        int l1 = i->X, l2 = j->X, r1 = i->Y, r2 = j->Y;
        if (i->Y > j->X) {
            cmp.erase(i);
            cmp.erase(j);
            cmp.emplace(l1, max(r1, r2));
            cnt++;
        } else {
            cmp.erase(i);
        }
        i = cmp.begin();
    }
    cout << cnt;
    return 0;
}