#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int solution(int n, vector<vector<int>> lighthouse) {
    int answer = 0;
    vector<int> light (lighthouse.size() + 2, 0);
    vector<set<int>> route (lighthouse.size() + 2);
    

    for (auto i : lighthouse){
        route[i[0]].insert(i[1]);
        route[i[1]].insert(i[0]);
    }
    
    // for (auto j : route){
    //     for (auto k : j){
    //         cout << k << ' ';
    //     }
    //     cout << endl;
    // }

    for (int end = 0; end != 1;){
        end = 1;
        for (int i = 1;  i < route.size() ; i++){
            if (route[i].size() != 0)
                end = 0;
            
            if (route[i].size() == 1){
                answer++;
                int temp = *route[i].begin();
                //cout << temp << endl;
                for (int j : route[temp]){
                    route[j].erase(temp);
                }
                route[i].clear();
                route[temp].clear();
                
                // int p = 0;
                // for (auto j : route){
                //     cout << p << ':';
                //     for (auto k : j){
                //         cout << k << ' ';
                //     }
                //     cout << j.size() ;
                //     cout << endl;
                //     p++;
                // }
                // cout << endl;
            }
        }
    }
    
    return answer;
}