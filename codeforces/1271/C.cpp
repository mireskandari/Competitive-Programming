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
    ll n, sx, sy;
    cin >> n >> sx >> sy;
    vector<pii> a(n);
    for (auto i : range(n)) cin >> a[i].X >> a[i].Y;
    auto InPath = [sx, sy](ll nx, ll ny, ll x, ll y) {
        ll dist1 = abs(x - sx) + abs(y - sy);
        ll dist2 = abs(x - nx) + abs(y - ny);
//        cerr << nx << ' ' << ny << ' ' << x << ' ' << y << ' ' << dist1 << ' ' << dist2 << '\n';
        return dist1 > dist2;
    };
    int const dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};
    pii c;
    int mx = 0;
    for (auto i : range(4)) {
        ll nx = sx + dx[i], ny = sy + dy[i];
        if (nx < 0 && nx > 1e9 && ny < 0 && ny > 1e9) continue;
        int cnt = 0;
        for (auto j : range(n)) {
            cnt += InPath(nx, ny, a[j].X, a[j].Y);
        }
        if (cnt > mx) {
            mx = cnt;
            c = {nx, ny};
        }
    }
    cout << mx << '\n' << c.X << ' ' << c.Y;
    return 0;
}