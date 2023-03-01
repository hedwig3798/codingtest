#include <string>
#include <vector>

using namespace std;
int answer = 0;

void search(int k, vector<vector<int>> dungeons, vector<int> flag, int now){
    for (int i = 0 ; i < flag.size(); i ++){
        
        if (flag[i] == 0 && dungeons[i][0] <= k){
            flag[i] = 1;
            search(k-dungeons[i][1], dungeons, flag, now+1);
            flag[i] = 0;
        }      
    }
    if (answer < now){
        answer = now;
    }
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<int>flag (dungeons.size(), 0);
    search(k, dungeons, flag, 0);
    return answer;
}
