#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define Len(x) (static_cast<int>(x.size()))

/* <not_serious> */
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
/* </not_serious> */
int constexpr MOD = 1e9 + 7;
ll constexpr INF = 1e9;


using pii = pair<int, int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        map<int, set<pii>, greater<>> sz;
        vector<int> a(n + 1);
        sz[n] = {{1, n}};
        for (auto i : range(1, n + 1)) {
            auto& now = sz.begin()->Y;
            pii best = *now.begin();
            if (Len(now) == 1) sz.erase(sz.begin());
            else sz.begin()->Y.erase(sz.begin()->Y.begin());
            int mid, len = best.Y - best.X + 1;
            if (len & 1) {
                mid = (best.Y + best.X) >> 1;
            } else {
                mid = (best.Y + best.X - 1) >> 1;
            }
            a[mid] = i;
            if (len & 1) {
                sz[len / 2].emplace(mid + 1, best.Y);
                sz[len / 2].emplace(best.X, mid - 1);
            } else {
                sz[len / 2 - 1].emplace(best.X, mid - 1);
                sz[len / 2].emplace(mid + 1, best.Y);
            }
//            for (auto j : range(1, n + 1)) cerr << a[j] << ' ';
//            cerr << '\n';
        }
        for (auto i : range(1, n + 1)) cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;
}