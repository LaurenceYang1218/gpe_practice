#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<long long> vec(60, 0);
void solve(string s){
    long long sign = 1, i, num = 0;
    char pos;
    for(i = 1; i < s.length(); ++i){
        if(s[i] == '-'){
            sign = -1;
        }else if((s[i] - '0') >= 0 && (s[i] - '0') < 9){
            num = 10 * num + (s[i] - '0');
        }else{
            pos = s[i];
            break;
        } 
    }
    num *= sign;
    //cout << num << " " << pos << endl;
    if(pos == '+'){
        solve(s.substr(i+1));
        long long d = vec[0];
        vec[0] = num;
        for(int i = 1; i < 50; ++i){
            long long t = vec[i];
            vec[i] = vec[i-1] + d;
            d = t; 
        }
    }else if(pos == '*'){
        solve(s.substr(i+1));
        vec[0] *= num;
        for(int i = 1; i < 50; ++i){
            vec[i] *= vec[i-1];
        }
    }else{
        for(int i = 0; i < 50; ++i){
            vec[i] = num;
        }
    }
}

int main(){
    string s;
    int n;
    while(cin >> s >> n){
        vec.clear();
        solve(s);
        for(int i = 0; i < n-1; ++i) {
            cout << vec[i] << ' ';
        }
        cout << vec[n-1] << '\n';
    }
    return 0;
}