#include <iostream>
#include <vector>
using namespace std;
vector<int> ans;

void solve(int k){
    while(k != 1){
        bool flag = true;
        int i = 9;
        while(flag){
            if(k % i == 0){
                ans.push_back(i);
                k /= i;
                break;
            }
            i--;
            if(i == 1) flag = false;
        }
        if(!flag){
            cout << -1 << '\n';
            return;
        }
    }
    for(vector<int>::reverse_iterator it = ans.rbegin(); it != ans.rend(); ++it){
        cout << *it;
    }
    cout << '\n';
}

int main(){
    int n, k;
    cin >> n;
    while(n--){ 
        ans.clear();
        cin >> k;
        if(k == 1){
            cout << 1 << '\n';
        }else{
            solve(k);
        }
    }
    return 0;
}