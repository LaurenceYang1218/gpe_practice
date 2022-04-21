#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    int num;
    while(cin >> num){
        if(num == 0) break;
        map<string, int> m;
        for(int i = 0; i < num; ++i){
            vector<string> frosh;
            string input, courses = "";
            for(int j = 0; j < 5; ++j){
                cin >> input;
                frosh.push_back(input);
            }
            sort(frosh.begin(), frosh.end());
            for(int j = 0; j < 5; ++j){
                courses += frosh[j];
            }
            ++m[courses];
            
            
        }
        int max_num = 0, total = 0;
        for(map<string, int>::iterator it = m.begin(); it != m.end(); ++it){
            if(it->second > max_num){
                max_num = it->second;
            }
        }
        for(map<string, int>::iterator it = m.begin(); it != m.end(); ++it){
            if(it->second == max_num){
                total += max_num;
            }
        }
        cout << total << '\n';
    }
    return 0;
}