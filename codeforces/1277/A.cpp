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
#define FOR(x, y, z) for(ll z = x; z < y; z++)
#define FORR(x, y, z) for(int z = x; z >= y; z--)

int MAIN(){
    int n;
    cin >> n;
    // cerr << n << endl;
    str nn = to_string(n);
    int t = (nn.size()-1) * 9;
    ll p = stoll(str(nn.size(), '1'));
    // cerr << "p " << p << endl;
    FOR(1, 10, i){
        // cerr << "pi " << p*i << endl;
        if(p*i <= n) t++;
    }
    cout << t << endl;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        MAIN();
    }
    return 0;
}