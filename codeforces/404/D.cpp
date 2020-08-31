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


int constexpr MOD = 1e9 + 7;

void norm(int64_t &a) {
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string s; cin >> s;
    int n = (int) s.size();

    // 0: zero adj
    // 1: one adj bomb on left
    // 2: one adj bomb on right
    // 3: two adj bomb
    // 4: contains bomb
    
    vll dp(5);
    dp[0] = dp[2] = 1;
    for (int i = 1; i <= n; ++i) {
        vll new_dp(5);
        auto c0 = [&]() { norm(new_dp[0] = dp[1] + dp[0]); };
        auto c1 = [&]() {
            new_dp[1] = dp[4];
            norm(new_dp[2] = dp[1] + dp[0]);
        };
        auto c2 = [&]() { new_dp[3] = dp[4]; };
        auto cs = [&]() {
            norm(new_dp[4] = dp[2] + dp[4]);
            norm(new_dp[4] += dp[3]);
        };

        switch (s[i - 1]) {
            case '0': c0(); break;
            case '1': c1(); break;
            case '2': c2(); break;
            case '*': cs(); break;
            default: c0(); c1(); c2(); cs(); break;
        }
        swap(dp, new_dp);
    }

    int64_t sum = 0;
    for (int i = 0; i < 5; ++i) {
        if (i == 2 || i == 3) continue;
        norm(sum += dp[i]);
    }
    cout << sum;
    return 0;
}
