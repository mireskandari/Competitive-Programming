#include <bits/stdc++.h>
using namespace std;

#define fast_io  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define sep      ' '
#define debug(x) cerr << #x << " = " << x << endl
#define getarr(arr, y) for(int i = 0; i < y; i++) cin >> arr[i]

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;

int q[100];
int main(){
    fast_io;
    int n, m, bus = 1, temp;
    cin >> n >> m;
    temp = m;
    getarr(q, n);
    for(int i = 0; i < n; i++){
        // debug(q[i]);
        while(q[i] != 0){
            if(q[i] <= temp){
                temp = temp - q[i];
                q[i] = 0;
            }
            else{
                bus++;
                temp = m;
            }
            // debug(bus);
        }
    }
    cout << bus << endl;
    
    return 0;
}