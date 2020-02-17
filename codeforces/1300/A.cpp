#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(int (z) = (x); (z) < (y); (z)++)
typedef int64_t ll;

int in[100];
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        int n, sum = 0, zero = 0, t = 0;
        cin >> n;

        forn(0, n, i) {
            cin >> in[i];
            if(in[i] == 0) zero++;
            sum += in[i];
        }
        
        t += zero;
        sum += zero;
        if(sum == 0) t++;
        cout << t << '\n';

    }
    return 0;
}