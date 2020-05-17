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



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    auto Solve = []() {
        int b, w;
        cin >> b >> w;
        if (b > 3 * w + 1 || w > 3 * b + 1) return cout << "NO\n", 0;
        cout << "YES\n";
        map<pair<int, int>, bool> mark;
        static auto Col = [](int x, int y) { return (x & 1) == (y & 1); };
        static auto Check = [](int x, int y) { return (x >= 0 && x < 1e9 && y >= 0 && y < 1e9); };
        static auto Dfs = [&](auto& F, int vx, int vy) -> void {
            mark[{vx, vy}] = true;
            if (Col(vx, vy) == 0) b--;
            else w--;
            cout << vx + 1 << ' ' << vy + 1 << '\n';
//            if (w == -10 || b == -10) return;
            if (w == 0 && b == 0) return;

            int const dy[] = {0, -1, 1, 0}, dx[] = {1, 0, 0, -1};
            for (auto i : range(1, 4)) {
                int nx = vx + dx[i], ny = vy + dy[i];
                if (Check(nx, ny) && !mark[{nx, ny}]) {
                    if (b == 0 && w == 0) return;
                    if (w - 1 > b && Col(nx, ny) == 1 && w > 0) {
                        w--;
                        mark[{nx, ny}] = true;
                        cout << nx + 1 << ' ' << ny + 1 << '\n';
                    } else if (b - 1 > w && Col(nx, ny) == 0 && b > 0) {
                        b--;
                        mark[{nx, ny}] = true;
                        cout << nx + 1 << ' ' << ny + 1 << '\n';
                    }
                }
            }
            F(F, vx + 1, vy);
        };
        Dfs(Dfs, 1, 3);
        return 0;
    };
    while (q--) {
        Solve();
    }
    return 0;
}