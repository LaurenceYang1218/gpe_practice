#include <iostream>
#include <vector>
using namespace std;

vector<int> add(vector<int>& a, vector<int>& b, int digit){
    vector<int> result(digit, 0);
    for(int i = 0; i < digit; ++i){
        result[i] = a[i] + b[i];
    }
    for(int i = 1; i < digit; ++i){
        if(result[i-1] >= 10){
            result[i] += (result[i-1] / 10);
            result[i-1] %= 10;
        }
    }
    return result;
}

int main(){
    int n, digit;
    cin >> n;
    bool flag = false;
    while(n--){
        if(n == 0) flag = true;
        cin >> digit;
        vector<int> a(digit, 0);
        vector<int> b(digit, 0);
        for(int i = digit-1; i >= 0; --i){
            cin >> a[i] >> b[i];
        }
        vector<int> result = add(a, b, digit);
        for(vector<int>::reverse_iterator it = result.rbegin(); it != result.rend(); ++it){
            cout << *it;
        }
        cout << '\n';
        if(!flag) cout << '\n';
    } 
    return 0;
}