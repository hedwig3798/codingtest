#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    int count = 0;
    int dis = abs(x-r) + abs(y-c);
    bool flag = false;
    
    if (dis % 2 != k % 2 || dis > k)
        return "impossible";
    
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
    
    dis = abs(x-r) + abs(y-c);
    //cout << count << ' ' << dis << ' ' << k << ' ' << k - count - dis << ' ';
    for (int i = 0 ; i < k - count - dis ; i += 2){
        answer += "rl";
    }
    
    for (int i = x ; i < r ; i++){
        answer += "d";
    }
    
    for (int i = y ; i > c ; i--){
        answer += "l";
    }
    
    for (int i = y ; i < c ; i++){
        answer += "r";
    }
    
    for (int i = x ; i > r ; i--){
        answer += "u";
    }
    
    //cout << answer;
    return answer;
}