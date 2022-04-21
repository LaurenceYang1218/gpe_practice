#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int> > lcs;
int main() {
    string m, n;
    while(cin >> m >> n){
        
        int len_m = m.length(), len_n = n.length();
        m = " " + m;
        n = " " + n;    
        lcs.resize(len_m+1);
        for(int i = 0; i <= len_m; ++i){
            lcs[i].resize(len_n+1);
        }
        for(int i = 0; i <= len_m; ++i){
            lcs[i][0] = 0;
        }
        for(int j = 0; j <= len_n; ++j){
            lcs[0][j] = 0;
        }
        for(int i = 1; i <= len_m; ++i){
            for(int j = 1; j <= len_n; ++j){
                if(m[i] == n[j]){
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                }else{
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
            }
        }
        if(lcs[len_m][len_n] != len_m) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}