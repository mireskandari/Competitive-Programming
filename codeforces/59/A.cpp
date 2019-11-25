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
    str s;
    cin >> s;
    int l = 0, u = 0;
    for(int i = 0; i < s.length(); i++){
        if(65 <= s[i] and s[i] <= 90) u++;
        if(65+32 <= s[i] and s[i] <= 90+32) l++;
    }
    if(l >= u)
        for(int i = 0; i < s.length(); i++){
            s[i] = ((65 <= s[i] and s[i] <= 90) ? s[i]+32 : s[i]);
        }
    else
        for(int i = 0; i < s.length(); i++){
            s[i] = ((65+32 <= s[i] and s[i] <= 90+32) ? s[i]-32 : s[i]);
        }
    cout << s;
    return 0;
}