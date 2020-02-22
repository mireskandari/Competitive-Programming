#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(int (z) = (x); (z) < (y); (z)++)
typedef int64_t ll;

long double d;
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int T;
    cin >> T;
    while(T--) {

        cin >> d;
        // a + b = d
        // a * b = d
        // -a**2 + da - d = 0
        long double a1 = (-d + sqrt(pow(d, 2) - 4 * d)) / -2;
        long double a2 = (-d - sqrt(pow(d, 2) - 4 * d)) / -2;
        if(!isnan(a1) || !isnan(a2)) {
            long double a = (!isnan(a1) ? a1 : a2);
            
            cout << setprecision(15) << fixed << "Y " << a << ' ' << d - a << '\n';
        } 
        else {
            cout << "N\n";
        }
    }
    return 0;
}