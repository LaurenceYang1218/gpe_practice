#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long n;
    while(cin >> n){
        if(n == 0) break;
        // find square number，which has odd number of factors.
        long long sqrt_n = sqrt(n);
        if(sqrt_n * sqrt_n != n){
            cout << "no\n";
        }else{
            cout << "yes\n";
        }
    }
    return 0;
}