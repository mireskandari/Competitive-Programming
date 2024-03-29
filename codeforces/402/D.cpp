#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
void err() { cerr << '\n'; }
template <class T, class ...A>
void err(T a, A ...b) {
    cerr << " " << a; err(b...);
}
#define dbg(a...) cerr << __LINE__ << " [" << #a << "]:", err(a)
#else
#define dbg(a...) 0
#endif

#define all(v) (v).begin(), (v).end()
using vll = vector<int64_t>;
using vi = vector<int>;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vi a(n); for (auto &i : a) cin >> i;
    vi b(m); for (auto &i : b) cin >> i;
    
    map<int, bool> is_bad;
    for (auto &i : b) is_bad[i] = true;

    vi pref(n);
    partial_sum(all(a), pref.begin(), [](int x, int y) {
        return __gcd(x, y);
    });
    
    // moral of the story : always save duplicate answers
    map<int, int> save_ans;

    int all_delta = 0;
    int last_delta = 0, last_div = 1;
    for (int i = n - 1; i >= 0; --i) {
        pref[i] /= last_div;
        all_delta += last_delta;
        int delta = 0, tmp = pref[i];
        if (!save_ans.count(pref[i])) {
            for (int64_t j = 2; j * j <= pref[i]; ++j) {
                bool bad = is_bad[j];
                while (pref[i] % j == 0) {
                    pref[i] /= j;
                    if (bad) ++delta;
                    else --delta;
                }
            }
            if (pref[i] > 1) {
                if (is_bad[pref[i]]) ++delta;
                else --delta;
            }
            save_ans[tmp] = -delta;
        }
        delta = -save_ans[tmp];
        if (delta > 0) {
            last_delta += delta;
            last_div *= tmp;
            all_delta += delta;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        int tmp = a[i];
        if (!save_ans.count(a[i])) {
            int delta = 0;
            for (int64_t j = 2; j * j <= a[i]; ++j) {
                bool bad = is_bad[j];
                while (a[i] % j == 0) {
                    a[i] /= j;
                    if (bad) --delta;
                    else ++delta;
                }
            }
            if (a[i] > 1) {
                if (is_bad[a[i]]) --delta;
                else ++delta;
            }
            save_ans[tmp] = delta;
        }
        all_delta += save_ans[tmp];
    }

    cout << all_delta;
    return 0;
}
