#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 숫자와 나온 횟수를 세는 구조체
struct n {
    int number;
    int count;
};
// 정렬 함수
bool cmp(n a, n b){
    if (a.count == b.count){
        return a.number < b.number;
    }
    return a.count > b.count;
}

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    // 구조체 백터
    vector<n> numbers;
    
    // 모든 숫자는 1단에서 한번씩 나오므로 각 숫자에 등장 횟수를 1로 초기화
    for (int i = 0 ; i <= e ; i ++){
        n temp;
        temp.number = i;
        temp.count = 1; 
        numbers.push_back(temp);
    }
    
    // 억억단 2단 부터 e 를 넘기지 않는 선에서 반복하여 숫자를 카운팅
    for (int i = 2; i <= e; i++){
        for (int j = 1 ; j <= e/i ; j++){
            numbers[i*j].count++;
        }
    }
    
    // 제한사항에 맞도록 정렬
    sort(numbers.begin(), numbers.end(), cmp);

    // 제한사항에 맞는 숫자만 나오도록
    for (int s : starts){
        for (int i = 0 ; i <= e ; i++){
            if (numbers[i].number >= s && numbers[i].number <= e){
                answer.push_back(numbers[i].number);
                break;
            }
        }
    }
    
    return answer;
}
