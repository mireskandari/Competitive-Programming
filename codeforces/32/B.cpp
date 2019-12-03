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
    str s;
    cin >> s;
    while(!s.empty()){
        if(s[0] == '.'){
             cout << 0;
             s.erase(0, 1);
        }
        if(s[0] == '-' and s[1] == '-'){
            cout << 2;
            s.erase(0, 2);
        } 
        else if(s[0] == '-' and s[1] == '.'){
            cout << 1;
            s.erase(0, 2);
        }
    }
    return 0;
}