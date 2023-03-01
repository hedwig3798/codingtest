#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 최대 크기
int max_ind;
// 함수 DP 함수 안에서도 numbers를 참조하기 위해
string num;
// 각 번호판에서 이동하는 비용
// ex) cost[0][9] 는 0 에서 9 로 이동하는 비용
int cost[][10] = {
    { 1, 7, 6, 7, 5, 4, 5, 3, 2, 3 },
    { 7, 1, 2, 4, 2, 3, 5, 4, 5, 6 },
    { 6, 2, 1, 2, 3, 2, 3, 5, 4, 5 },
    { 7, 4, 2, 1, 5, 3, 2, 6, 5, 4 },
    { 5, 2, 3, 5, 1, 2, 4, 2, 3, 5 },
    { 4, 3, 2, 3, 2, 1, 2, 3, 2, 3 },
    { 5, 5, 3, 2, 4, 2, 1, 5, 3, 2 },
    { 3, 4, 5, 6, 2, 3, 5, 1, 2, 4 },
    { 2, 5, 4, 5, 3, 2, 3, 2, 1, 2 },
    { 3, 6, 5, 4, 5, 3, 2, 4, 2, 1 }
};

// DP 함수
int s (int ind, int left, int right, int dp[][10][10]) {
    // 더 이상 나아갈 수 없을때
    if (max_ind == ind){
        return 0;
    }
    
    // 이미 해당 상황에 대한 결과가 있다면 그 값을 가져와서 불필요한 작업 제외
    if (dp[ind][left][right] != -1){
        return dp[ind][left][right];
    }
    
    // 최솟값 비교를 위한 int 최댓값 입력
    int result = 2147483647;
    // char 형식의 숫자를 int 형식으로 변환
    int now = int(num[ind] - '0');
  
    // 왼손으로 누르는 경우
    if (now != right){
        result = min(result, s(ind+1, now, right, dp) + cost[left][now]);
    }
    // 오른손으로 누르는 경우
    if (now != left){
        result = min(result, s(ind+1, left, now, dp) + cost[right][now]);
    }
    
    // 결과를 배열에 저장하여 해당 상황이 다시 나올 경우 호출
    dp[ind][left][right] = result;

    return result;
}

int solution(string numbers) {
    int answer = 0;
    // numbers의 길이에 따라 배열 생성
    // 동적 할당이 필요 없으므로 백터 대신 배열을 사용
    int dp [numbers.size()][10][10];
     
    // 문자열 복사
    num = numbers;
    // 최대 길이 저장
    max_ind = numbers.size();
    // 배열을 -1로 초기화 하여 한번 있던 상황인지 
    fill(&dp[0][0][0], &dp[numbers.size()-1][9][10], -1);
    
    return answer = s(0, 4, 6, dp);
}
