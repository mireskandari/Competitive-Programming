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
    int n, h, w = 0;
    cin >> n >> h;
    FOR(0, n, i){
        int c; cin >> c;
        w += (c > h ? 2 : 1);
    }
    cout << w << endl;
    return 0;
}