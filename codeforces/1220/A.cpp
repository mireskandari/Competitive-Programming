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

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    str s;
    // bitset<64> sb;
    unsigned long long si;
    cin >> n >> s;
    int zero = count(all(s), 'z');
    int one = count(all(s), 'n');
    // cerr << zero << sep << one;
    s = str(one, '1') + str(zero, '0');
    // cerr << s << endl;
    
    FOR(0, s.size(), i) {
        cout << s[i] << sep;
    }
    return 0;
}