#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define X first
#define Y second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)

void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << H << ' ';
    debug_out(T...);
}

int constexpr N = 1e5;
int constexpr MOD = 1e9 + 7;
int constexpr INF = 1e9;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    bool done = false;
    string out;
    forn (0, n, i) {
        string s;
        cin >> s;
        if (!done) {
            forn (1, s.size(), j) {
                if (s[j] == 'O' && s[j - 1] == 'O') {
                    s[j] = '+';
                    s[j - 1] = '+';
                    done = true;
                    break;
                }
            }
        }
        out += s + '\n';
//        cout << s << '\n';
    }
    cout << (done ? "YES\n" + out : "NO");
    return 0;
}