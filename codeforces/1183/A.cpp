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
    int a;
    cin >> a;
    int sum = 0, aa = a;
    while (aa) {
        sum += aa % 10;
        aa /= 10;
    }
    while (sum % 4 != 0) {
        sum = 0;
        aa = ++a;
        while (aa) {
            sum += aa % 10;
            aa /= 10;
        }
    }
    cout << a;
    return 0;
}