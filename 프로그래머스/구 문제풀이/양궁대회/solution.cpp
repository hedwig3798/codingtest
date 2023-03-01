#include <string>
#include <vector>

using namespace std;

vector<int> answer(1, -1);
int max_s = 0;

// 디버깅용 백터 출력 함수
void pprint(vector<int> temp){
    for (int t: temp){
        printf("%d ", t);
    }
    printf("\n");
}

// 낮은 화살 갯수가 많은지 체크
bool is_low(vector<int> &answer, vector<int> &rion){
    for (int i = 10; i >=0; i--){
        if (answer[i] > rion[i]){
            return false;
        }
        else if (answer[i] < rion[i]){
            return true;
        }
    }
}

// 점수 차이 계산
int get_score(vector<int> &rion, vector<int> &ap){
    int rs = 0;
    int as = 0;
    
    for (int i = 0; i < 11 ; i++){
        if (rion[i] > ap[i]){
            rs += 10 - i;
        }
        else if(ap[i] != 0){
            as += 10 - i;
        }
    }
    return rs - as;
}

// 완전 탐색
// 공간 활용을 위해 배열을 하나만 사용
void search(int index, int arrow, vector<int> &rion, vector<int> &ap){
    // 배열의 끝 이거나 화살을 전부 소모하였을 경우
    if (index == 11 || arrow == 0){
        int s = get_score(rion, ap);
        rion[10] += arrow;
        if (s > max_s && s > 0){
            max_s = s;
            answer = rion;
        }
        else if (s == max_s && is_low(answer, rion)){
            answer = rion;
        }
        // 다음 탐색을 위해 배열 초기화
        rion[10] -= arrow;
        return;
    }
    
    else {
        // 화살을 쏠 경우
        if (arrow > ap[index]){
            rion[index] += ap[index]+1;
            search(index+1, arrow-ap[index]-1, rion, ap);
            // 다음 탐색을 위해 배열 초기화
            rion[index] -= ap[index]+1;
        }
        // 쏘지 않을 
        search(index+1, arrow, rion, ap);
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> rion(11,0);
    search(0, n, rion, info);
    return answer;
}
