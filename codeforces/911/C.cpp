#include <bits/stdc++.h>

using namespace std;

#ifndef HELLO_PEOPLE
#define cerr if(0) cout
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k[4];
    cin >> k[1] >> k[2] >> k[3];

    auto &&yes = []() { cout << "YES"; exit(0); };
    auto &&no = []() {cout << "NO"; exit(0); };

    if (count(k + 1, k + 4, 2) >= 2 || count(k + 1, k + 4, 3) == 3 || count(k + 1, k + 4, 1)) {
        yes();
    }

    sort(k + 1, k + 4);
    if (k[1] == 2 && k[2] == 4 && k[3] == 4) yes();

    no();
    return 0;
}