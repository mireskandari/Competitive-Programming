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
    ll n, k;
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        if(n % 10 == 0){
            n /= 10;
        }
        else{
            n--;
        }
    }
    cout << n << endl;
    return 0;
}