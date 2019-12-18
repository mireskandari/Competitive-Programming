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
    int n, t = 0;
    str a;
    cin >> n >> a;
    for(int i = 1; i < a.length();){
        // debug(a);
        // debug(i);
        if(a[i] == a[i-1]){
            t ++;
            a.erase(i, 1);
        }
        else{
            i ++;
        }
    }
    // debug(a);
    cout << t;
    return 0;
}