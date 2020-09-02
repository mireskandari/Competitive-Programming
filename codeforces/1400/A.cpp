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
#define long int64_t
using vll = vector<long>;
using vi = vector<int>;


signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        string s; cin >> s;
        string ans;
        for (int i = 0; i < (int) s.size(); i += 2) {
            ans += s[i];
        }
        cout << ans << '\n';
    }
    return 0;
}
