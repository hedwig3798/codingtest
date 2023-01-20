#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

// 차이나는 알파벳 수가 1개 이하인지 (중복되는 알파벳이 없으므로 0인 경우는 없다.)
bool compare_string(string a, string b){
    int result = 0;
    
    for (int i = 0 ; i < a.length() ; i++){
        if (a[i] != b[i]){
            result ++;
        }
        if (result > 1)
            return false;
    }
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    // begin 에서 해당 string 까지의거리를 담을 map.
    map<string, int> flag;
    // bfs를 위한 큐
    queue<string> q;
    // target이 words에 없는 경우 예외처리
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;
    
    // flag 초기화
    for (auto i : words){
        flag.insert({i, 0});
    }
    flag.insert({begin, 0});
    // 큐 시작에 시작점 입력
    q.push(begin);
    // 큐가 빌 때까지 탐색
    for (;!q.empty();){
        // 큐의 값과 단어를 하나씩 비교
        for (int i = 0 ; i < words.size() ; i++){
            // 한번도 간 적이 없으면서 비교함수가 참일때
            if (compare_string(q.front(), words[i]) && flag[words[i]] == 0){
                // 타깃을 찾은 경우 바로 거리를 리턴
                if (target == words[i]){
                    return flag[q.front()] + 1;
                }
                // 자기 자신인 경우
                else if (words[i] == q.front())
                    continue;
                // 타깃과 자기 자신이 아닌경우 큐에 넣는다.
                q.push(words[i]);
                // 거리 입력
                flag[words[i]] = flag[q.front()] + 1;;
            }
        }
        // 큐에서 해당 값 제외
        q.pop();
    }
    return answer;
}
