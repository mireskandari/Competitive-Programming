#include <bits/stdc++.h>
using namespace std;

#define fast_io  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define sep      ' '
#define debug(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;


int main(){
    fast_io;
    ll n, sum1 = 0, sum2 = 0;
    str k;
    cin >> n >> k;
    for(int i = 0; i < n / 2; i++){
        // debug(k);
        if(k.substr(k.length()-1, 1) != "7"  && k.substr(k.length()-1, 1) != "4"){
            cout << "NO";
            return 0;
        }
        sum1 += stoi(k.substr(k.length()-1, 1));
        k = k.substr(0, k.length()-1);
    }
    // cout << "hello" << endl;
    for(int i = n / 2; i < n; i++){
        // debug(k);
        if(k.substr(k.length()-1, 1) != "7"  && k.substr(k.length()-1, 1) != "4"){
            cout << "NO";
            return 0;
        }
        sum2 += stoi(k.substr(k.length()-1, 1));
        k = k.substr(0, k.length()-1);
    }
    // debug(sum1);
    // debug(sum2);
    cout << (sum1 == sum2 ? "YES" : "NO");

    return 0;
}