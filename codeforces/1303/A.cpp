#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

char s[101];
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    while(tc--) {

        s[0] = '\0';
        cin >> s;
        size_t t1 = 0, t2 = 0;
        size_t n = strlen(s);
        forn(0, n, i) {
            if(s[i] == '1') break;
            t1++;
        }   
        reverse(s, s + n);
        // cout << "fuck";
        forn(0, n, i) {
            if(s[i] == '1') break;
            t2++;
        }   
        reverse(s, s + n);
        cout << (s + n - t2 > s + t1 ? count(s + t1, s + n - t2, '0') : 0) << '\n';
    }
    return 0;
}