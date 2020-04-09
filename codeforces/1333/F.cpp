#include <bits/stdc++.h>
using namespace std;

int mx[500010];
void sieve(int n) {
    for (int i = 1; i <= n; i++) mx[i] = 1;
    for (long long i = 2; i * i <= n; i++) {
        if (mx[i] == 1) {
            for (int j = 2 * i; j <= n; j += i) {
                if (mx[j] == 1) mx[j] = j / i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    sieve(n);
    sort(mx + 2, mx + n + 1);
    for (int i = 2; i <= n; i++) cout << mx[i] << ' ';
    return 0;
}