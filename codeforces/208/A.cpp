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

    string s, ss;
    cin >> s;
    for (int i = 0; i < s.size();) {
        bool af = false;
        while (i < s.size() - 2 && s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B') {
            i += 3;
            af = true;
        }
        if (i < s.size()) {
            if (af) ss += ' ';
            ss += s[i];
            i++;
        }
    }
    int j = 0, jj = 0;
    forn (0, ss.size(), i) {
        if (ss[i] == ' ') {
            j++;
        } else {
            break;
        }
    }
    forn (0, ss.size(), i) {
        if(ss[ss.size() - i - 1] == ' ') {
            jj++;
        } else {
            break;
        }
    }
    cout << ss.substr(j, ss.size() - j - jj);
    return 0;
}