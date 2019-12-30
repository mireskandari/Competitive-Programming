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
    int na, nb, k, m, ma, mi;
    cin >> na >> nb >> k >> m;
    FOR(0, na, i) {
        int temp;
        cin >> temp;
        if (i == k - 1) mi = temp;
    }
    FOR(0, nb, i) {
        int temp;
        cin >> temp;
        if (i == nb - m) ma = temp;
    }
    // cerr << mi << sep << ma << endl;
    cout << (ma > mi ? "YES" : "NO");
    return 0;
}