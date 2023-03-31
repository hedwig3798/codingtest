#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for (auto b : balls){
        int bx = b[0];
        int by = b[1];
        int path = INT_MAX;
        
        if (!(startY == by && startX > bx))
            path = min(path, (int)pow(-bx - startX, 2) + (int)pow(by - startY, 2));

        if (!(startX == bx && startY > by))
            path = min(path, (int)pow(bx - startX, 2) + (int)pow(-by - startY, 2));

        if (!(startY == by && startX < bx))
            path = min(path, (int)pow((bx + (m-bx)*2) - startX, 2) + (int)pow(by - startY, 2));

        if (!(startX == bx && startY < by))
            path = min(path, (int)pow(bx - startX, 2) + (int)pow((by + (n-by)*2) - startY, 2));

        answer.push_back(path);
    }
    
    return answer;
}