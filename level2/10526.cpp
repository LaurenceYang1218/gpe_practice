#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> multiply(vector<int>& vec_a, vector<int>& vec_b){
    vector<int> result(500, 0);
    for(int i = 0; i < 250; ++i){
        for(int j = 0; j < 250; ++j){
            result[i+j] += (vec_a[i] * vec_b[j]);
        }
    }
    for(int i = 1; i < 499; ++i){
        result[i] += (result[i-1] / 10);
        result[i-1] %= 10;
    }
    return result;
}

int main() {
    string a, b;
    vector<int> vec_a, vec_b, ans;
    while(cin >> a >> b){
        vec_a.clear(); vec_b.clear(); ans.clear();
        vec_a.resize(250, 0); vec_b.resize(250, 0);
        int len_a = a.length(), len_b = b.length();
        for(int i = 0; i < len_a; ++i){
            vec_a[i] = (a[len_a-i-1] - '0');
        }
        for(int i = 0; i < len_b; ++i){
            vec_b[i] = (b[len_b-i-1] - '0');
        }
        ans = multiply(vec_a, vec_b);
        int idx = 0;
        for(int i = ans.size()-1; i >= 0; --i){
            if(ans[i] != 0) {
                idx = i;
                break;
            }
        }
        for(int i = idx; i >= 0; --i){
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}