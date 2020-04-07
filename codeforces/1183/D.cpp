#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> cnt(n + 1, 0);
        rep (0, n, i) {
            int a;
            cin >> a;
            cnt[a]++;
        }
        sort(1 + all(cnt), greater<>());
        int lst = cnt[1];
        ll count = cnt[1];
        cerr << count << '\n';
        rep (2, n + 1, i) {

            if (lst == 0) break;
            if (cnt[i] >= lst) {
                lst = lst - 1;
            } else {
                lst = cnt[i];
            }
            count += lst;
        }

        cout << count << '\n';
    }
    return 0;
}