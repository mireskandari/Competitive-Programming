#include <bits/stdc++.h>
using namespace std;

#define fast_io  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define debug(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef long double ld;

int n;
int main(){
    fast_io;
    cin >> n;
    for(int i = n+1; i < 10000; i++){
        bool is_ok = true;
        // debug(i);
        for(int j = 0; j < 4; j++){
            for(int f = j+1; f < 4; f++){
                int a = i / (int)pow(10, f) % 10;
                int b = i / (int)pow(10, j) % 10;
                if(a == b){
                    // debug(j);
                    // debug(f);
                    is_ok = false;
                    break;
                }
            }
            if(!is_ok){
                break;
            }
        }
        if(is_ok){
            cout << i << endl;
            return 0;
        }
    }
}