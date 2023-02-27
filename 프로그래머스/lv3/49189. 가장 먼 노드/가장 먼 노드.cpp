#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> graph (n, vector<int>());
    
    for (auto i : edge){
        graph[i[0]-1].push_back(i[1]-1);
        graph[i[1]-1].push_back(i[0]-1);
    }
    
    // for (auto i : graph){
    //     for (auto j : i){
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }
    
    queue<int> q;
    vector<int> dis(n, -1);
    dis[0] = 0;
    q.push(0);
    
    for (;!q.empty();){
        int now = q.front();
        
        q.pop();
        for (auto i : graph[now]){
            if (dis[i] == -1){
                dis[i] = dis[now] + 1;
                q.push(i);
            }
        }
    }
    
    sort(dis.begin(), dis.end(), greater<int>());
    
    int temp = dis[0];
    for (auto i : dis){
        if (i == temp)
            answer++;
        else
            break;
    }
    
    return answer;
}