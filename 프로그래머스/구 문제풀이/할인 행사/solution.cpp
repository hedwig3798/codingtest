#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string, int> which;
    map<string, int> w;
    
    // 사야하는 목록의 map 구현
    for (int i = 0; i < want.size(); i++){
        which.insert(pair(want[i], number[i]));
    }
    
    // 반복 최소화를 위해 사이즈 조정
    for (int i = 0; i < discount.size() - 9; i ++){
        // 초기 map구조 만들기
        if (i == 0){
            for (int j = 0; j < 10; j++){
                if (w.find(discount[j]) == w.end()){
                    w.insert(pair(discount[j], 1));
                }
                else {
                    w[discount[j]]++;
                }
            }
        }
        
        // 현재 날짜에서 10번째 날 까지의 할인 물품 목록
        // 이전일 빼고 10번째 날 더하기
        else {
            w[discount[i-1]]--;
            if (w[discount[i-1]] == 0){
                w.erase(discount[i-1]);
            }
            
            if (w.find(discount[i+9]) == w.end()){
                w.insert(pair(discount[i+9], 1));
            }
            else {
                w[discount[i+9]]++;
            } 
        }

        // 순회 플래그
        int check = 1;
        for (auto k: which){
            if (w.find(k.first) == w.end()){
                check = 0;
                break;
            }
            else{
                if (w[k.first] < k.second){
                    check = 0;
                    break;
                }
            }
        }
        
        if (check == 1){
            answer++;
        }
        
        
    }
    
    return answer;
}
