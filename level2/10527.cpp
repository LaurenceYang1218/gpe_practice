#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    vector<int> vec;
    while(cin >> n){
        vec.push_back(n);
        sort(vec.begin(), vec.end());
        int len = vec.size();
        if(len % 2 == 0){
            cout << (vec[(len/2)-1] + vec[(len/2)]) / 2 << '\n';
        }else{
            cout << vec[len/2] << '\n';
        }
    }
    return 0;
}