#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    string s1, s2, s3, s;
    cin >> s1 >> s2 >> s3;
    s = s1 + s2;
    sort(all(s));
    sort(all(s3));
    cout << (s == s3 ? "YES" : "NO");
    return 0;
}