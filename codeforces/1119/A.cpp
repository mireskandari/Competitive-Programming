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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> in(n);
    rep (0, n, i) cin >> in[i];
    int i = 0;
    while (i < n && in[i] == in[n - 1]) i++;
    int maax = n - 1 - i;
    i = n - 1;
    while (i >= 0 && in[i] == in[0]) i--;
    maax = max(i, maax);
    cout << maax;
    return 0;
}