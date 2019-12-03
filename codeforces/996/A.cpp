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
    int bill[5] = {100, 20, 10, 5, 1};
    int n, sum = 0, i = 0;
    cin >> n;
    while(n != 0){
        if(n / bill[i] > 0){
            sum += (n / bill[i]);
            n -= (n / bill[i]) * bill[i];
        } 
        else i += 1;
    }
    cout << sum;
    return 0;
}