#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(int (z) = (x); (z) < (y); (z)++)
typedef int64_t ll;

char s[200001];
int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, k;
    cin >> n >> k >> s;
    if(k >= 1 && n == 1) {
        cout << 0; 
        return 0;
    }

    for(int i = 0, j = 0; j < k && i < n; i++) {
        if((i == 0 && s[i] == '1') || s[i] == '0') continue;
        else {
            if(i == 0) {
                s[i] = '1';
            }
            else {
                s[i] = '0';
            }
            j++;
        }
    }
    cout << s;
    return 0;
}