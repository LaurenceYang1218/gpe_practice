#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n, m;
    int cases = 1;
    vector<string> ans, test;
    while(true) {
        ans.clear(); test.clear();
        cin  >> n;
        if(n == 0) break;
        string s;
        cin.ignore();
        for(int i = 0; i < n; ++i){
            getline(cin, s);
            ans.push_back(s);
        }
        cin >> m;
        cin.ignore();
        for(int i = 0; i < m; ++i){
            getline(cin, s);
            test.push_back(s);
        }
        cout << "Run #" << cases++ << ": ";
        vector<int> ans_num, test_num;
        ans_num.clear(); test_num.clear();
        if(ans == test){
            cout << "Accepted\n";
        }else{
            for(int i = 0; i < ans.size(); ++i){
                for(int j = 0; j < ans[i].length(); ++j){
                    if(ans[i][j] >= '0' && ans[i][j] <= '9'){
                        ans_num.push_back((ans[i][j] - '0'));
                    }
                }
            }
            for(int i = 0; i < test.size(); ++i){
                for(int j = 0; j < test[i].length(); ++j){
                    if(test[i][j] >= '0' && test[i][j] <= '9'){
                        test_num.push_back((test[i][j] - '0'));
                    }
                }
            }
            if(ans_num == test_num){
                cout << "Presentation Error\n";
            }else{
                cout << "Wrong Answer\n";
            }
        }
    }
    return 0;
}