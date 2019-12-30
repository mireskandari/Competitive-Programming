#include <bits/stdc++.h>
using namespace std;

#define sep ' '
#define endl '\n'
#define FOR(x, y, z) for(int z = x; z < y; z++)
#define FORR(x, y, z) for(int z = x; z >= y; z--)
typedef long long ll;
typedef long double ld;
typedef string str;


int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    FOR(0, T, i){
        ll h, m;
        cin >> h >> m;
        // cerr << (23 - h) * 60 << endl;
        cout << ((23 - h) * 60) + (60 - m) << endl;
    }
    return 0;
}