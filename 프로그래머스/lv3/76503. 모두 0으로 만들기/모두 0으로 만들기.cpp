#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

long long dfs(vector<vector<int>> &route_map, vector<long long> &a, vector<bool> &is_visit, int now, long long &answer){
    is_visit[now] = true;
    
    for (auto i : route_map[now]){
        if (!is_visit[i])
            a[now] += dfs(route_map, a, is_visit, i, answer);
    }
    
    long long val = a[now];
    answer += abs(val);
    a[now] = 0;
    // for (auto i : a){
    //     cout << i << endl;
    // }
    // cout << endl;
    //cout << now << ' ' << val << endl;
    return val;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    vector<long long> aa;
    vector<vector<int>> route_map(a.size());
    vector<bool> is_visit(a.size(), false);
    
    for (auto i : edges){
        route_map[i[0]].push_back(i[1]);
        route_map[i[1]].push_back(i[0]);
    }
    
    for (auto i : a){
        aa.push_back((long long)i);
    }
    
    long long temp = dfs(route_map, aa, is_visit, 0, answer);
    //cout << temp;
    // for (auto i : route_map){
    //     for (auto j : i){
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }
    
    
    
    if (temp != 0)
        return -1;
    return answer;
}