#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(int (z) = (x); (z) < (y); (z)++)
typedef int64_t ll;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int a, b, c;
    cin >> a >> b;
    c = (6 - max(a, b) + 1);
    int d = __gcd(c, 6);
    cout << c / d << '/' << 6 / d;
    return 0;
}