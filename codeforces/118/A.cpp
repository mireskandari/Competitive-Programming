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

    string s;
    cin >> s;
    vector<char> mark(s.size(), 0);
    forn (0, int(s.size()), i) {
        static string v = "AOYEUI";
        mark[i] = count(all(v), toupper(s[i])) != 0 ? 1 : 0;
    }
    forn (0, s.size(), i) {
        if (!mark[i]) cout << '.' << char(tolower(s[i]));
    }

    return 0;
}