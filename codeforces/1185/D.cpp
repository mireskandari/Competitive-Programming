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
    int n; cin >> n;
    vi a(n), idx(n); 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        idx[i] = i;
    }
    sort(all(idx), [&](int x, int y) {
        return a[x] < a[y];
    });
    sort(all(a));
    
    map<int, int> cnt;
    for (int i = 1; i < n; ++i) {
        cnt[a[i] - a[i - 1]]++;
    }
    
    auto do_shit = [&](int i) {
        if (i >= 1) {
            cnt[a[i] - a[i - 1]]--;
            if (cnt[a[i] - a[i - 1]] == 0) cnt.erase(a[i] - a[i - 1]);
        }
        if (i < n - 1) {
            cnt[a[i + 1] - a[i]]--;
            if (cnt[a[i + 1] - a[i]] == 0) cnt.erase(a[i + 1] - a[i]);
        }
        if (i >= 1 && i < n - 1) cnt[a[i + 1] - a[i - 1]]++;
        
        int sz = (int) cnt.size();
        if (i >= 1) cnt[a[i] - a[i - 1]]++;
        if (i < n - 1) cnt[a[i + 1] - a[i]]++;
        if (i >= 1 && i < n - 1) {
            cnt[a[i + 1] - a[i - 1]]--;
            if (cnt[a[i + 1] - a[i - 1]] == 0) cnt.erase(a[i + 1] - a[i - 1]);
        }
        return sz <= 1;
    };

    for (int i = 0; i < n; ++i) {
        if (do_shit(i)) {
            cout << idx[i] + 1;
            exit(0);
        }
    }
    
    cout << -1;
    return 0;
}
