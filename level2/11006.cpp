#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<vector<char> > map;
vector<vector<bool> > visited;
vector<pair<char, int> > dict;
int m, n;
void DFS(int x, int y){
    visited[x][y] = true;
    if(x+1 < m && !visited[x+1][y] && map[x+1][y] == map[x][y])  DFS(x+1, y);
    if(x-1 >= 0 && !visited[x-1][y] && map[x-1][y] == map[x][y]) DFS(x-1, y);
    if(y+1 < n && !visited[x][y+1] && map[x][y+1] == map[x][y])  DFS(x, y+1);
    if(y-1 >= 0 && !visited[x][y-1] && map[x][y-1] == map[x][y]) DFS(x, y-1);
    return;
}

bool comp(pair<char, int> p1, pair<char, int> p2){
    if(p1.second > p2.second){
        return true;
    }else if(p1.second == p2.second){
        return p1.first < p2.first;
    }else{
        return false;
    }
}

int main(){
    //DFS to traverse all the area
    int k;
    cin >> k;
    for(int i = 1; i <= k; ++i){
        map.clear(); visited.clear(); dict.clear();
        cin >> m >> n;
        map.resize(m);
        visited.resize(m);
        // for(auto it: dict) cout << it.first << " " << it.second << endl;
        for(int j = 0; j < m; ++j){
            map[j].resize(n);
            visited[j].resize(n);
        }
        for(int j = 0; j < m; ++j){
            for(int k = 0; k < n; ++k){
                cin >> map[j][k];
                visited[j][k] = false;
            }
        }
        
        for(int j = 0; j < m; ++j){
            for(int k = 0; k < n; ++k){
                if(!visited[j][k]){
                    vector<pair<char, int> >::iterator it;
                    for(it = dict.begin(); it != dict.end(); ++it){
                        if(it->first == map[j][k]){
                            it->second++;
                            break;
                        }
                    }
                    if(it == dict.end()){
                        dict.push_back(make_pair(map[j][k], 1)); 
                    }
                    DFS(j, k);
                }
            }
        }
        cout << "World #" << i << '\n';
        sort(dict.begin(), dict.end(), comp);
        for(vector<pair<char, int> >::iterator it = dict.begin(); it != dict.end(); it++){
            cout << it->first << ": " << it->second << '\n';
        }
        
    }

    return 0;
}