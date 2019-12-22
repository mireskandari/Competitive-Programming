#include <bits/stdc++.h>
using namespace std;

#define sep              ' '
#define endl             '\n'
#define FOR(x, y, z)     for(int z = x; z < y; z++)

typedef long long ll;
typedef long double ld;
typedef string str;


int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    cout << (1 + 3 * (n * (n + 1))) << endl;
    return 0;
}