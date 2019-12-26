#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef string str;
#define all(x) (x).begin(),(x).end()
#define X first
#define Y second
#define sep ' '
#define endl '\n'
#define Mp make_pair
#define FOR(x, y, z) for(int z = x; z < y; z++)
#define FORR(x, y, z) for(int z = x; z >= y; z--)

int MAIN(){
    str p, h;
    cin >> p >> h;
    sort(all(p));
    if(h.size() < p.size()){
        cout << "NO" << endl;
        return 0;
    }
    FOR (0, h.size() - p.size() + 1, i){
        str s = h.substr(i, p.size());
        sort(all(s));
        if (s == p){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        // cerr << T << endl;
        MAIN();
    }
    return 0;
}