#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string strs[] = {   "c0111001111", "d0111001110",
                        "e0111001100", "f0111001000",
                        "g0111000000", "a0110000000",
                        "b0100000000", "C0010000000",
                        "D1111001110", "E1111001100",
                        "F1111001000", "G1111000000",
                        "A1110000000", "B1100000000"
                    };
    vector<string> table(strs, strs+(sizeof(strs)/sizeof(string)));
    string n; int int_n;
    getline(cin, n);
    stringstream ss(n);
    ss >> int_n;
    for(int i = 0; i < int_n; ++i){
        string next;
        string current = "0000000000"; 
        vector<int> count(10, 0);
        string s; 
        getline(cin, s);
        for(int j = 0; j < s.length() && s[j] != ' '; ++j){
            for(int k = 0; k < 14; ++k){
                if(s[j] == table[k][0]){
                    next = table[k].substr(1, 10);
                }
            }
            for(int k = 0; k < 10; ++k){
                if(current[k] == '0' && next[k] == '1'){
                    count[k]++;
                }
            }
            current = next;                
        } 
        for(int j = 0; j < 9; ++j){
            cout << count[j] << " ";
        }
        cout << count[9] << '\n';
    }
    return 0;
}