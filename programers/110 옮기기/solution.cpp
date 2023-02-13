#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    // s 벡터 안에 있는 문자열에 대하여
    for (auto ss : s){
        // "110" 개수를 제거한 문자열을 얻기 위한 스텍
        stack <char> sstack;
        // "110"의 개수
        int count = 0;
        // 문자열의 길이만큼 반복
        for (int i = 0 ; i < ss.length() ; i++){
            // 스텍에 문자를 넣음
            sstack.push(ss[i]);
            // 만일 스텍의 크기가 3 이상인 경우 스텍의 앞부분이 "110"인지 파악
            if (sstack.size() >= 3){
                char thi = sstack.top();
                sstack.pop();
                char sec = sstack.top();
                sstack.pop();
                char fir = sstack.top();
                sstack.pop();
                // "110"인 경우 갯수를 증가
                if (fir == '1' && sec == '1' && thi == '0'){
                    count++;
                }
                // 아닌경우 다시 스텍에 넣음
                else {
                    sstack.push(fir);
                    sstack.push(sec);
                    sstack.push(thi);
                }
            }
        }
        // "110"이 엎는경우 문자열을 그대로 출력
        if (count == 0){
            answer.push_back(ss);
            continue;
        }
        
        // "110"이 있는경우
        // 어느 곳에 "110"을 삽입해야 하는지
        int ind = sstack.size();
        // 임시 문자열
        string temp = "";
        // 스텍이 비거나, 남은 문자열 뒤에서 연속된 1이 있는 경우 인덱스를 앞으로 당긴
        for (;!sstack.empty() && sstack.top() == '1';){
            ind--;
            temp = sstack.top() + temp;
            sstack.pop();
        }
        // 더이상 연속된 1이 없는 경우 남은 문자를 문자열에 더함
        for (;!sstack.empty();){
            temp = sstack.top() + temp;
            sstack.pop();
        }
        // 인덱스 위치에 제거한 "110"만큼 
        for (;count > 0 ; count -= 1){
            temp.insert(ind, "110");
        }
        
        answer.push_back(temp);
    }
    
    
    return answer;
}
