#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(){
    string a, b;
    map<char, int> dict_a, dict_b;
    while(cin >> a >> b){
        dict_a.clear(); dict_b.clear();
        for(int i = 0; i < a.length(); ++i){
            ++dict_a[a[i]];
        }
        for(int i = 0; i < b.length(); ++i){
            ++dict_b[b[i]];
        }
        string s;
        for(map<char, int>::iterator it1 = dict_a.begin(); it1 != dict_a.end(); ++it1){
            map<char, int>::iterator it2 = dict_b.find(it1->first);
            if(it2 != dict_b.end()){
                int len = min(it1->second, it2->second);
                for(int i = 0; i < len; ++i){
                    s += it1->first;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}