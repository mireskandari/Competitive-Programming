#include <bits/stdc++.h>
using namespace std;

#define fast_io          ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define sep              ' '
#define debug(x)         cerr << #x << " = " << x << endl
#define getarr(arr, y)   for(int i = 0; i < y; i++) cin >> arr[i]
#define printarr(arr, y) for(int i = 0; i < y; i++) cerr << i << " = " << arr[i] << endl

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;
int poww(int a, int b){
    
}

int main(){
    fast_io;
    ll x;
    cin >> x;
    // cout << floor(log2l(x)) << endl;
    cout << __builtin_popcount(x);
    return 0;
}