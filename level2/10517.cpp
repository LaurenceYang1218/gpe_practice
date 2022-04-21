#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num, days, party_num, period;
    cin >> num;
    vector<bool> table;
    while(num--){
        table.clear();
        cin >> days;
        table.resize(days+1, false);
        cin >> party_num;
        for(int i = 0; i < party_num; ++i){
            cin >> period;
            for(int j = 1; j <= days; ++j){
                if(j % period == 0 && j % 7 != 6 && j % 7 != 0){
                    table[j] = true;
                }
            }
        }   
        int cnt = 0;
        for(int i = 1; i < table.size(); ++i){
            if(table[i]) {
              cnt++;
            }
        }
        cout << cnt << '\n';
    }
    

    return 0;
}