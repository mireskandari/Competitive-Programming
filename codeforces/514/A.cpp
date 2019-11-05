#include <iostream>
#include <limits.h>

using namespace std;
int main(){
    unsigned long long int n, n_, a, p;
    int k;
    cin >> n;
    n_ = n;
    a = n;
    p = 1;
    while(n_ > 0){
        k = n_ % 10;
        if(k > 9 - k){
            a -= p * k;
            k = 9 - k;
            a += p * k;
        }
        p *= 10;
        n_ /= 10; 
        // cout << a << endl;
        // cout << p << endl << endl;
    } 
    if(a / (p/10) == 0){
        a += 9 * (p/10);
    }
    cout << a << endl;

}