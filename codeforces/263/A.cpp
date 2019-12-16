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
    int temp, x, y;
    for(int i = 0; i < 5; i ++){
        for(int j = 0; j < 5; j ++){
            cin >> temp;
            if(temp == 1){
                x = i;
                y = j;
            }
        }
    }
    cout << abs(2 - x) + abs(2 - y);
    return 0;
}