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
    int n;
    str s, alpha("abcdefghijklmnopqrstuvwxyz");
    cin >> n >> s;
    for(int i = 0; i < alpha.length(); i++){
        if(s.find(alpha[i]) != s.npos or s.find(alpha[i] + ('A' - 'a')) != s.npos){}
        else{
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}