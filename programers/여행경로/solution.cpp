#include <bits/stdc++.h>

using namespace std;
// dfs 함수
bool dfs(vector<string> &answer, vector<vector<string>> &tickets, vector<bool> &visit, string cur){
    // 현재 위치를 정답에 넣고 제한 사항에 맞는지 확인
    answer.push_back(cur);
    if (answer.size() == tickets.size()+1)
        return true;
    // 탐색
    for (int i = 0 ; i < tickets.size() ; i++){
        // 만일 현재 위치에서 출발하는 사용하지 않은 티켓이 있다면
        if (tickets[i][0] == cur && !visit[i]){
            // 해당 티켓을 사용
            visit[i] = true;
            // 그 결과로 경로가 나온다면 리턴
            if (dfs(answer, tickets, visit, tickets[i][1]))
                return true;
            // 아니라면 취소하고 다른 결과를 찾음
            visit[i] = false;
        }
    }
    // 더이상 경로가 없는경우 이곳으로 갈 필요가 없다
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    // 방문 체크
    vector<bool> visit(tickets.size(), false);
    // 알파벳  순으로 가기 위하여
    sort(tickets.begin(), tickets.end());
    // dfs 
    dfs(answer, tickets, visit, "ICN");
    
    return answer;
}
