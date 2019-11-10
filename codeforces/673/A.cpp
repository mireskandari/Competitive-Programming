#include <bits/stdc++.h>
using namespace std;

#define fast_io  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define sep      ' '
#define debug(x) cerr << #x << " = " << x << endl
#define getarr(arr, y) for(int i = 1; i < y+1; i++) cin >> arr[i]

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;

int q[92];
int main(){
    fast_io;
    int n;
    cin >> n;
    getarr(q, n);
    q[n+1] = 90;
    q[0] = 0;
    for(int i = 0; i < n+1; i++){
        if(q[i+1] - q[i] > 15){
            cout << q[i] + 15;
            return 0;
        }
    }
    cout << 90;
    return 0;
}