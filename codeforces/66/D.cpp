#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
bool is_prime(ll a) {
    for (ll i = 2; i * i <= a; ++i) {
        if (a % i == 0) return false;
    }
    return true;
}
signed main() {
    ll n;
    scanf("%lld", &n);
    if (n == 2) {
        puts("-1");
        exit(0);
    }
    printf("%lld\n%lld\n", 2ll * 3, 2ll * 5);
    for (ll i = 0, p = 7; i < n - 2; ++i) {
        while (!is_prime(p)) ++p;
        printf("%lld\n", p * 3 * 5);
        ++p;
    }
}