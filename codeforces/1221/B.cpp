#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
void err() { cerr << '\n'; }
template <class T, class ...A>
void err(T a, A ...b) {
    cerr << " " << a; err(b...);
}
#define dbg(a...) cerr << "[" << #a << "]:", err(a)
#else
#define dbg(a...) 0
#endif

#define all(v) (v).begin(), (v).end()
using vll = vector<int64_t>; using vi = vector<int>;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ((i & 1) == (j & 1) ? 'W' : 'B');
        }
        cout << '\n';
    }
    return 0;
}
