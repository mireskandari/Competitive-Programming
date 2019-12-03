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

int p[100];
int main(){
    fast_io;
    int n, k, left = 0, right = 0;
    cin >> n >> k;
    getarr(p, n);
    for(int i = 0; i < n; i++){
        if(p[i] <= k) left++;
        else break;
    }
    for(int i = n-1; i >= 0; i--){
        if(p[i] <= k) right++;
        else break;
    }
    cout << (left+right > n ? n : left+right);
    return 0;
}