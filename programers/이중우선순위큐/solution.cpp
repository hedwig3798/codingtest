#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    // 우선순위 큐 2개 생성 오름차순과 내림차순
    priority_queue <int, vector<int>, greater<int>> min_h;
    priority_queue <int, vector<int>, less<int>> max_h;
    // 큐의 사이즈 측정
    int size = 0;
    
    for (auto i : operations){
        // 입력인 경우 해당 숫자를 두 큐 모두에 입력하고 사이즈 증가
        if (i[0] == 'I'){
            string s = i.substr(2);
            int number = stoi(s);
            max_h.push(number);
            min_h.push(number);
            size++;
        }
        // 입력이 아닌데 사이즈가 0 인경우 무시
        else if (size == 0){
            continue;
        }
        // 최댓값 pop후 사이즈 축소
        else if (i == "D 1"){
            max_h.pop();
            size--;
        }
        // 최솟값 pop후 사이즈 축소
        else if (i == "D -1"){
            min_h.pop();
            size--;
        }
        
        // 최종적으로 사이즈가 0 인경우 두 큐를 초기화
        if (size == 0){
            while(!max_h.empty()) max_h.pop();
            while(!min_h.empty()) min_h.pop();
        }
    }
    
    // 사이즈가 0 인경우 [0,0]
    if (size == 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    // 아닌경우 
    else {
        answer.push_back(max_h.top());
        answer.push_back(min_h.top());
    }
    
    
    return answer;
}
