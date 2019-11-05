#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m, maxx, temp, mm, a;
    cin >> n >> m;
    maxx = 0;
    for(int i = 1; i <= n; i++){
        cin >> temp;
        a = temp / m + ((temp % m + 1)/2 - (temp % m - 1)/2);
        if(a >= maxx){
            maxx = a;
            mm = i;
        }
    }
    cout << mm << endl;


}