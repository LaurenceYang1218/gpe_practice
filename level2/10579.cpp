#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    map<string, int> dict;
    string s; 
    int cost;
    for(int i = 0; i < m; ++i){
        cin >> s >> cost;
        dict.insert(make_pair(s, cost));
    }
    string p;
    for(int i = 0; i < n; ++i){
        int ans = 0;
        while(cin >> p){
            if(p == ".") break;
            map<string, int>::iterator it = dict.find(p);
            if(it != dict.end()){
               ans += it->second; 
            }
        }
        cout << ans << '\n';
    }
    return 0;
}