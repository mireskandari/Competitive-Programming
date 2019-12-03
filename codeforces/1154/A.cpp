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

int x[4];
int main(){
    fast_io;
    int abc;
    cin >> x[0] >> x[1] >> x[2] >> x[3];
    abc = max(max(max(x[0], x[1]), x[2]), x[3]);
    for(int i = 0; i < 4; i++){
        if(abc - x[i] > 0) cout << abc - x[i] << sep;
    }
    
    return 0;
}