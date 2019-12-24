#include <bits/stdc++.h>
using namespace std;

#define sep ' '
#define endl '\n'
#define FOR(x, y, z) for(int z = x; z < y; z++)
#define FORR(x, y, z) for(int z = x; z >= y; z--)
typedef long long ll;
typedef long double ld;
typedef string str;


ll comb(ll n, ll k){
    ll r = 1;
    ll d;
    if (k > n) return 0;
    for (d=1; d <= k; d++) {
    r *= n--;
    r /= d;
    }
    return r;
}
vector<int> nn;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    FOR(0, n, i){
        int a; cin >> a;
        nn.push_back(a);
    }
    int a = *max_element(nn.begin(), nn.end());
    int b = *min_element(nn.begin(), nn.end());
    cout << a - b << sep;
    if(a == b){
        cout << comb(1LL * count(nn.begin(), nn.end(), a), 1LL * 2);
    }
    else{
        cout << 1LL * count(nn.begin(), nn.end(), a) * count(nn.begin(), nn.end(), b);
    }
    return 0;
}