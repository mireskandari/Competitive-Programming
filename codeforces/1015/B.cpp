#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(int (z) = (x); (z) < (y); (z)++)
typedef int64_t ll;

int p[2][26];
char s[51], t[51];
vector<pair<int, char>> q;
vector<int> moves;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n >> s >> t;

    forn(0, n, i) {
        p[0][(s[i] - 'a')]++;
        p[1][(t[i] - 'a')]++;
        q.push_back(make_pair(i, t[i]));
    }
    forn(0, 26, i) {
        if(p[0][i] != p[1][i]) {
            cout << -1;
            return 0;
        }
    }
    sort(all(q));
    forn(0, n, i) {
        int l2 = q.back().F;
        char c = q.back().S;
        q.pop_back();
        int l1 = find(s, s + n, c) - s;
        forn(l1, l2, j) {
            moves.push_back(j);
            swap(s[j], s[j + 1]);
        }
    }
    cout << moves.size() << '\n';
    for(int m : moves) {
        cout << m + 1 << ' ';
    }
    // cout << s;
    return 0;
}