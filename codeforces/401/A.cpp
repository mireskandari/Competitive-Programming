#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, x, temp, t;
    long long int m;
    cin >> n >> x;
    t = 0;
    m = 0;
    for(int i = 0; i < n; i++){
        cin >> temp;
        m += temp;
    }
    m = abs(m);
    while(m >= x){
        t++;
        m = m - x;
    }
    if(m % x > 0){
        t++;
    }
    cout << t << endl;
}