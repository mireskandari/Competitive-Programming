#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(int (z) = (x); (z) < (y); (z)++)
typedef int64_t ll;

// char in[1000001];
string in;
int a[4], sum;
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    forn(0, 4, i) cin >> a[i];
    cin >> in;
    sum = 0;
    // cout << in;
    sum = accumulate(all(in), 0, [] (int csum, char value) {
        return a[(value - '0') - 1] + csum;
    });
    cout << sum;
    return 0;
}