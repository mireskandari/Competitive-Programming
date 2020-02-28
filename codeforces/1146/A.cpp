#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    string s;
    cin >> s;
    int a = count(all(s), 'a');
    cout << (a > s.size() / 2 ? s.size() : 2 * a - 1);
    return 0;
}