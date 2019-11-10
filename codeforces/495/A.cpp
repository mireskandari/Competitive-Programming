#include <bits/stdc++.h>
using namespace std;

#define fast_io  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define sep      ' '
#define debug(x) cerr << #x << " = " << x << endl
#define getarr(arr, y) for(int i = 0; i < y; i++) cin >> arr[i]
#define printarr(arr, y) for(int i = 0; i < y; i++) cerr << i << " = " << arr[i] << endl

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;


int main(){
    fast_io;
    str a;
    cin >> a;
    int t = 1;
    for(int i = 0; i < 2; i++){
        if(a[i] == '0') t *= 2;
        if(a[i] == '1') t *= 7;
        if(a[i] == '2') t *= 2;
        if(a[i] == '3') t *= 3;
        if(a[i] == '4') t *= 3;
        if(a[i] == '5') t *= 4;
        if(a[i] == '6') t *= 2;
        if(a[i] == '7') t *= 5;
        if(a[i] == '8') t *= 1;
        if(a[i] == '9') t *= 2; 
    }
    cout << t;
    return 0;
}