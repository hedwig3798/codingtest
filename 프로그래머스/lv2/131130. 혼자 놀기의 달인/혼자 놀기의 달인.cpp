#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    vector<int> flag;
    vector<vector<int>> c;
    flag.assign(cards.size(), 0);
    
    for (int i = 0; i < cards.size(); i++){
        if (flag[i] != 0){
            continue;
        }
        
        else {
            c.push_back(vector<int>());
            c.back().push_back(cards[i]);
            flag[i]++;
            while(1){
                int now = c.back().back();
                if (flag[now-1] != 0){
                    break;
                }
                c.back().push_back(cards[now-1]);
                flag[now-1] ++;
            }
        }
    }
    // for (auto a : c){
    //     for (auto v: a){
    //         printf("%d ", v);
    //     }
    //     printf("\n");
    // }
    
    vector<int> ccc;
    
    for (vector<int> t : c){
        ccc.push_back(t.size());
    }
    
    sort(ccc.rbegin(), ccc.rend());
    
    if (c.size() <= 1){
        return 0;
    }
    
    return ccc[0] * ccc[1];
}