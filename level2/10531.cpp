#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main(){
    map<string, int> dict;
    string s;
    int n;
    bool f = false;
    while(cin >> n){
        if(f) cout << '\n';
        f = true;
        dict.clear();
        while(getline(cin, s)){
            if(s == "EndOfText") break;
            for(int i = 0; i < s.length(); ++i){
                if(isupper(s[i]) || islower(s[i])) 
                    s[i] = tolower(s[i]);
                else
                    s[i] = ' ';
            }
            stringstream ss(s);
            string word;
            while(ss >> word){
                dict[word]++;
            }
        }
        bool flag = false;
        for(map<string, int>::iterator it = dict.begin(); it != dict.end(); ++it){
            if(it->second == n && it->first.length() > 0){
                cout << it->first << '\n';
                flag = true;
            }
        }
        if(!flag) cout << "There is no such word.\n";       
    }

    return 0;
}