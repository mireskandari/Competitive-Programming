#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define rep(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        vector<vector<char>> table(9, vector<char>(9));
        rep (0, 9, i) {
            rep (0, 9, j) {
                cin >> table[i][j];
            }
        }
        vector<vector<char>> center(3, vector<char>(3));
        for (int i = 0, ii = 1; i < 3; i++, ii += 3) {
            for (int j = 0, jj = 1; j < 3; j++, jj += 3) {
                center[i][j] = table[ii][jj];
            }
        }
        table[1][0] = center[0][0];
        table[0][4] = center[0][1];
        table[2][7] = center[0][2];
        table[3][1] = center[1][0];
        table[4][3] = center[1][1];
        table[5][6] = center[1][2];
        table[7][2] = center[2][0];
        table[8][5] = center[2][1];
        table[6][8] = center[2][2];
        cerr << '\n';
        rep (0, 9, i) {
            rep (0, 9, j) {
                cout << table[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}