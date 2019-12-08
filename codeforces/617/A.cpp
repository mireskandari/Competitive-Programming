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


int main(){
    fast_io;
    int n, c = 0;
    cin >> n;
    while(n > 0){
        if(n >= 5){
            n -= 5;
            c ++;
        }
        else if(n >= 4){
            n -= 5;
            c ++;
        }
        else if(n >= 3){
            n -= 5;
            c ++;
        }
        else if(n >= 2){
            n -= 5;
            c ++;
        }
        else if(n >= 1){
            n -= 5;
            c ++;
        }
    }
    cout << c;
    return 0;
}