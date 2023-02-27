#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<string> &answer, vector<vector<string>> &tickets, vector<bool> &visit, string cur){
    answer.push_back(cur);
    if (answer.size() == tickets.size()+1)
        return true;
    for (int i = 0 ; i < tickets.size() ; i++){
        if (tickets[i][0] == cur && !visit[i]){
            visit[i] = true;
            if (dfs(answer, tickets, visit, tickets[i][1]))
                return true;
            visit[i] = false;
        }
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visit(tickets.size(), false);

    stack<string> s;
    
    sort(tickets.begin(), tickets.end());
    
    dfs(answer, tickets, visit, "ICN");
    
    return answer;
}