#include <bits/stdc++.h>
using namespace std;

#define fast_io  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define sep      ' '
#define debug(x) cerr << #x << " = " << (x) << endl
#define getarr(arr, y) for(int i = 0; i < (y); i++) cin >> (arr)[i]
#define printarr(arr, y) for(int i = 0; i < (y); i++) cerr << i << " = " << (arr)[i] << endl

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;


int main(){
    fast_io;
    str in, h("hello");
    int last = 0;
    bool found;
    cin >> in;
//    cout << in;
    for(int j = 0; j < h.length(); j++){
        found = false;
        for(int i = last; i < in.length(); i++) {
//            debug(in[i]);
//            debug(h[j]);
            if (in[i] == h[j]) {
                last = i + 1;
                found = true;
                break;
            }
        }
//        debug(last);
//        debug(found);
        cout << endl << endl;
        if(!found){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}