#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define FV first
#define SV second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, k;
    cin >> n >> k;
    // vector<int> in(n);
    // forn (0, n, i) cin >> in[i];

    int rm = 240 - k, cnt = 0;
    for (int i = 1; i < n + 1 && rm - 5 * i >= 0; i++) {
        rm -= 5 * i;
        cnt++;
    }
    cout << cnt;
    return 0;
}