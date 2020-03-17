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

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int l, r;
    cin >> l >> r;
    forn (l, r + 1, i) {
        bool mark[10];
        fill(mark, mark + 10, 0);
        int t = i;
        while (t > 0) {
            if (!mark[t % 10]) {
                mark[t % 10] = 1;
            } else {
                t = INT_MAX;
                break;
            }
            t /= 10;
        }
        if (t != INT_MAX) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}