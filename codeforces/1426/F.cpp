#include <bits/stdc++.h>
using namespace std;

constexpr int P = 1000 * 1000 * 1000 + 7;

void Add(long long &a, long long b) {
    a += b;
    if (a >= P) a -= P;
}

void Mult(long long &a, long long b) {
    a = a * b % P;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long a = 0, ab = 0, abc = 0, cnt = 1;
    for (int i = 0; i < n; ++i)
        switch (s[i]) {
            case 'a':
                Add(a, cnt);
                break;
            case 'b':
                Add(ab, a);
                break;
            case 'c':
                Add(abc, ab);
                break;
            case '?':
                long long na = a, nab = ab, nabc = abc;
                Mult(na, 3);
                Add(na, cnt);
                Mult(nab, 3);
                Add(nab, a);
                Mult(nabc, 3);
                Add(nabc, ab);
                Mult(cnt, 3);
                swap(a, na), swap(ab, nab), swap(abc, nabc);
                break;
        }
    cout << abc;
    return 0;
}
