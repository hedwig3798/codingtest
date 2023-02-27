#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_ind;
string num;
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

int s (int ind, int left, int right, int dp[][10][10]) {

    if (max_ind == ind){
        return 0;
    }
    
    if (dp[ind][left][right] != -1){
        return dp[ind][left][right];
    }
    
    int result = 2147483647;
    int now = int(num[ind] - '0');
    if (now != right){
        result = min(result, s(ind+1, now, right, dp) + cost[left][now]);
    }
    if (now != left){
        result = min(result, s(ind+1, left, now, dp) + cost[right][now]);
    }
 
    dp[ind][left][right] = result;

    return result;
}

int solution(string numbers) {
    int answer = 0;
    int dp [numbers.size()][10][10];
    
    num = numbers;
    max_ind = numbers.size();
    
    fill(&dp[0][0][0], &dp[numbers.size()-1][9][10], -1);
    
    return answer = s(0, 4, 6, dp);
}