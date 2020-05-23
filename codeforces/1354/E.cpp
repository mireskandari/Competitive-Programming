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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    auto g = new vector<int>[n];
    for (auto i : range(m)) {
        int v, u;
        cin >> v >> u;
        g[--v].emplace_back(--u);
        g[u].emplace_back(v);
    }
    vector<char> mark(n, false), col(n);
    vector<int> d(n);
    auto Dfs = [&](auto& F, int v, int& r, int& l,
                vector<int>& c) {

        mark[v] = true;
        c.emplace_back(v);
        (col[v] ? r : l)++;
        for (auto u : g[v]) {
            if (mark[u] && (d[u] - d[v]) % 2 == 0) {
                return false;
            }
        }
        for (auto u : g[v]) {
            if (!mark[u]) {
                col[u] = !col[v];
                d[u] = d[v] + 1;
                if(!F(F, u, r, l, c)) return false;
            }
        }
        return true;
    };
    int cnt = 0;
    vector<pair<int, int>> cmp;
    vector<vector<int>> c;
    for (auto i : range(n)) {
        if (!mark[i]) {
            col[i] = false;
            d[i] = 0;
            cnt++;
            cmp.emplace_back();
            c.emplace_back();
            if (!Dfs(Dfs, i, cmp.back().Y, cmp.back().X, c.back())) {
                cout << "NO\n";
                return 0;
            };
        }
    }
    if (cnt == 1) {
        if (count(all(col), false) == n2) {
            cout << "YES\n";
            for (auto i : range(n)) {
                if (!col[i]) cout << 2;
                else {
                    cout << (n1 > 0 ? 1 : 3);
                    if (!n1) n3--;
                    else n1--;
                }
            }
            return 0;
        } else if (count(all(col), true) == n2) {
            cout << "YES\n";
            for (auto i : range(n)) col[i] = !col[i];
            for (auto i : range(n)) {
                if (!col[i]) cout << 2;
                else {
                    cout << (n1 ? 1 : 3);
                    if (!n1) n3--;
                    else n1--;
                }
            }
            return 0;
        }
    }
    auto dp = vec(cnt + 1, n2 + 1, -1);
    dp[0][0] = 0;
    for (auto i : range(cnt)) {
        for (auto j : range(n2 + 1)) {
            if (dp[i][j] != -1) {
                if (j + cmp[i].X <= n2) dp[i + 1][j + cmp[i].X] = 0;
                if (j + cmp[i].Y <= n2) dp[i + 1][j + cmp[i].Y] = 1;
            }
        }
    }
    if (dp[cnt][n2] == -1) {
        cout << "NO\n";
        return 0;
    }
    int i = cnt, j = n2;
    while (i > 0 && j >= 0) {
        if (dp[i][j] == 0) {
            for (auto v : c[i - 1]) {
                if (!col[v]) col[v] = 2;
                else {
                    col[v] = (n1 ? 1 : 3);
                    if (!n1) n3--;
                    else n1--;
                }
            }
            j -= cmp[i - 1].X;
        } else if (dp[i][j] == 1) {
            for (auto v : c[i - 1]) col[v] = !col[v];
            for (auto v : c[i - 1]) {
                if (!col[v]) col[v] = 2;
                else {
                    col[v] = (n1 ? 1 : 3);
                    if (!n1) n3--;
                    else n1--;
                }
            }
            j -= cmp[i - 1].Y;
        }
        i--;
    }
    cout << "YES\n";
    for (auto x : range(n)) cout << int(col[x]);
    return 0;
}