#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define forn(x, y, z) for(ll (z) = (x); (z) < (y); (z)++)


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    int t = min(a, min(b / 2, c / 4));
    cout << t + t * 2 + t * 4;
    return 0;
}