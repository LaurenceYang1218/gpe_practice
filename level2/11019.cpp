#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<vector<int> > vec(3);
    for(int i = 0; i < 3; ++i){
        vec[i].resize(4);
    }

    int n;
    string inst;
    while(cin >> n){
        if(n == 0) break;
        vec[0][0] = 2;
        vec[1][0] = 1;
        vec[2][0] = 5;
        vec[1][1] = 4;
        vec[1][2] = 6;
        vec[1][3] = 3;
        while(n--){    
            cin >> inst;
            if(inst == "north"){
                int tmp = vec[0][0];
                vec[0][0] = vec[1][0];
                vec[1][0] = vec[2][0];
                vec[2][0] = vec[1][2];
                vec[1][2] = tmp;
            }else if(inst == "south"){
                int tmp = vec[0][0];
                vec[0][0] = vec[1][2];
                vec[1][2] = vec[2][0];
                vec[2][0] = vec[1][0];
                vec[1][0] = tmp;
            }else if(inst == "east"){
                int tmp = vec[1][3];
                vec[1][3] = vec[1][2];
                vec[1][2] = vec[1][1];
                vec[1][1] = vec[1][0];
                vec[1][0] = tmp;
            }else if(inst == "west"){
                int tmp = vec[1][0];
                vec[1][0] = vec[1][1];
                vec[1][1] = vec[1][2];
                vec[1][2] = vec[1][3];
                vec[1][3] = tmp;
            }
        }
        cout << vec[1][0] << '\n';
    }
    return 0;
}