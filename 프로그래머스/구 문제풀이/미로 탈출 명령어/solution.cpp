#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    // 얼마나 이동 했는지
    int count = 0;
    // 현재 위치에서 목적지 까지의 거리
    int dis = abs(x-r) + abs(y-c);
    // 최단거리인지
    bool flag = false;
    
    // k 와 가야되는 거리의 짝홀 여부가 같아야 갈 수 있으므로
    // 또한 최단 거리가 k 보다 길면 무조건 도달 불가능
    if (dis % 2 != k % 2 || dis > k)
        return "impossible";
    
    // 최단 거리가 될 때까지, 혹은 좌표의 맨 아래에 도달 할 때 까지 아래 이동
    for (int i = x ; i < n ; i++){
        answer += "d";
        x++;
        dis = abs(x-r) + abs(y-c);
        count++;
        if ((dis+count) == k){
            flag = true;
            break;
        }
    }
    
    // 최단 거리가 될 때까지, 혹은 좌표의 맨 오른쪽 끝에 도달 할 때 까지 왼쪽 이동
    for (int i = y ; i > 1 && !flag ; i--){
        answer += "l";
        y--;
        dis = abs(x-r) + abs(y-c);
        count++;
        if ((dis+count) == k){
            flag = true;
            break;
        }
    }
    // 거리 최신화
    dis = abs(x-r) + abs(y-c);
  
    // 거리 여유가 있다면 없을 때 까지 무의미한 이동 반복
    // 사전상 이 방법이 가장 앞에 오는 방법이므로
    for (int i = 0 ; i < k - count - dis ; i += 2){
        answer += "rl";
    }
    
    // 남은 거리는 최단 거리 이므로 이동하면 끝
    // d l r u 순으로 이동하여야 사전상 앞에 
  
    // 아래로
    for (int i = x ; i < r ; i++){
        answer += "d";
    }
    
    // 왼쪽으로
    for (int i = y ; i > c ; i--){
        answer += "l";
    }
    
    // 오른쪽으로
    for (int i = y ; i < c ; i++){
        answer += "r";
    }
    
    // 위로
    for (int i = x ; i > r ; i--){
        answer += "u";
    }
  
    return answer;
}
