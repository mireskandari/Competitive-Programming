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
    unsigned long long n, ans;
    cin >> n;
    ans = pow(2, n + 1) - 2;
    cout << ans;
    return 0;
}