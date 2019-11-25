#include <bits/stdc++.h>
using namespace std;

#define fast_io  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define sep      ' '
#define debug(x) cerr << #x << " = " << (x) << endl
#define getarr(arr, y) for(int i = 0; i < (y); i++) cin >> (arr)[i]
#define printarr(arr, y) for(int i = 0; i < (y); i++) cerr << i << " = " << (arr)[i] << endl

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;


int main(){
    fast_io;
    str pos;
    int c1 = 0, c0 = 0;
    cin >> pos;
    for(int i = 0; i < pos.length(); i++){
        c1 = (pos[i] == '1' ? c1 + 1 : 0);
        c0 = (pos[i] == '0' ? c0 + 1 : 0);
        if(c1 == 7 || c0 == 7){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}