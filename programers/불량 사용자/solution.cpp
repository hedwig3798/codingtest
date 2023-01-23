#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 문자가 서로 짝이 되는지 체크하는 함수
bool check_same(string u, string b){
    if (u.length() != b.length())
        return false;
    for (int i = 0 ; i < u.length() ; i++){
        if (b[i] == '*')
            continue;
        if (b[i] != u[i])
            return false;
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    // 조합을 위한 임시벡터
    vector<int> temp (user_id.size(), 1);
    // 제제사용자 만큼 0으로 앞부분을 채움
    for (int i = 0; i < banned_id.size() ; i++){
        temp[i] = 0;
    }
    
    // 조합 구하기
    do{
        // 조합이 들어갈 벡터
        vector<string> ts;
        // 조합을 구하여 벡터에 넣음
        for (int i = 0; i < temp.size() ; i++){
            if (temp[i] == 0){
                ts.push_back(user_id[i]);
            }
        }
        
        // 순열을 위해 오름차순 정렬
        sort(ts.begin(), ts.end());
        
        // 순열 구하기
        do{
            // 정답인지 아닌지 파악을 위해
            int flag = 1;
            // 각 자리의 있는 문자가 서로 짝인지 체크
            for (int i = 0; i < ts.size(); i++){
                // 짝이 아니라면 오답이므로 반복 해제
                if (! check_same(ts[i], banned_id[i])){
                    flag = 0;
                    break;
                }
            }
            // 만일 모두 짝이라면 정답이므로 +1
            // 정답인 경우 더이상 순열을 돌 필요가 없으므로 끝
            if (flag == 1){
                answer++;
                break;
            }
        }while (next_permutation(ts.begin(), ts.end()));
        
    }while (next_permutation(temp.begin(), temp.end()));
    
    return answer;
}
