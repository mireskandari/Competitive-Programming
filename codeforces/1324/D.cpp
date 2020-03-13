#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << H << ' ';
    debug_out(T...);
}

int constexpr N = 2e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;


int a[N], b[N], c1[N], c2[N];
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    forn (0, n, i) cin >> a[i];
    forn (0, n, i) cin >> b[i];

    ll cnteq = 0;
    forn (0, n, i) {
        c1[i] = a[i] - b[i];
        c2[i] = -c1[i];
        if (c1[i] > c2[i]) cnteq++;
    }

    sort(c1, c1 + n);
    sort(c2, c2 + n);

    ll cntgr = 0;
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (c1[i] > c2[j]) {
            j++;
            cntgr += n - i;
        } else {
            i++;
        }
    }
    cout << (cntgr - cnteq) / 2;
    return 0;
}