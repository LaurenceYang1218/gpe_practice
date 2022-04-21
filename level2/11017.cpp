#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string m, n;
    while(cin >> m >> n){
        vector<vector<int> > lcs;
        lcs.resize(m.length()+1);
        for(int i = 0; i <= m.length(); ++i){
            lcs[i].resize(n.length()+1);
        }
        int len_m = m.length();
        int len_n = n.length();
        m = " " + m;
        n = " " + n;
        for(int i = 1; i <= len_m; ++i){
            for(int j = 1; j <= len_n; ++j){
                if(m[i] == n[j]) {
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                }else {
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
            }
        }
        cout << lcs[len_m][len_n] << '\n';
    }
    return 0;
}