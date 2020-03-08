#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define FV first
#define SV second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

char s[20];
int fact[10];
int constexpr p[10][3] =   {{0, 0, 0},
                            {0, 0, 0},
                            {2, 0, 0},
                            {3, 0, 0},
                            {2, 2, 0},
                            {5, 0, 0},
                            {2, 3, 0},
                            {7, 0, 0},
                            {2, 2, 2},
                            {3, 3, 0}};
int main() {
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n >> s;
    
    forn (0, n, i) {
        // cout << s[i] << ' ';
        int c = s[i] - '0';
        // cout << c << ' '
        forn (1, c + 1, x) {
            forn (0, 3, y) {
                fact[p[x][y]]++;
            }
        }
    }
    for (int i = 9; i >= 1; i--) {
        forn (0, fact[i], x) {
            forn (1, i, j) {
                forn (0, 3, y) {
                    fact[p[j][y]]--;
                }
            }
        }
        cout << string(fact[i], char(i + '0'));
    }
    
    return 0;
}