#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

void dfs(vector<vector<int>> &users, vector<int> &emoticons, vector<int> &discount, vector<int> &disinfo, vector<vector<int>> &able, int depth){
    if (depth == emoticons.size()){
        
        int join = 0;
        int buy = 0;
        for (auto u : users){
            int cost = 0;
            for (int e = 0 ; e < emoticons.size() ; e++){
                if (u[0] <= disinfo[e]){
                    cost += emoticons[e] - (emoticons[e] * ((float)disinfo[e]/100));
                }
                //cout << u[0] << ' ' << disinfo[e] << ' ' << cost << endl;
            }
            if (cost >= u[1]){
                join++;
            }
            else {
                buy += cost;
            }
        }
        cout << endl;
        able.push_back({join, buy});
    }
    else {
        for (auto d : discount){
            disinfo[depth] = d;
            dfs(users, emoticons, discount, disinfo, able, depth+1);
        }
    }
}

bool cmp(vector<int>a, vector<int> b){
    if (a[0] == b[0])
        return a[1] > b[1];
    else
        return a[0] > b[0];
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<int> discount = {10, 20, 30, 40};
    vector<int> disinfo(emoticons.size());
    vector<vector<int>> able;
    
    dfs(users, emoticons, discount, disinfo, able, 0);
    

    sort(able.begin(), able.end(), cmp);
    
    // for (auto i : able){
    //     cout << i[0] << ' ' << i[1] << endl;
    // }
    
    return able[0];
}