#include <bits/stdc++.h>
using namespace std;

#define fast_io  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define debug(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef long double ld;

int n, tf, tf2, curr;
int main(){
    fast_io;
    cin >> n;
    tf = 0;
    tf2 = 0;
    for(int i = 0; i < n; i++){
        cin >> curr;
        if(curr == 25){
            tf++;
            continue;
        }
        else if(curr == 50){
            if(tf == 0){
                cout << "NO" << endl;
                return 0;
            }
            tf--;
            tf2++;
            continue;
        }
         else if(curr == 100){
            if(tf >= 1 && tf2 >= 1){
                tf--;
                tf2--;
            }
            else if(tf >= 3 && tf2 == 0){
                tf -= 3;
            }
            else{
                cout << "NO" << endl;
                return 0;
            }
            
        }
    }
    cout << "YES" << endl;
    return 0;
}