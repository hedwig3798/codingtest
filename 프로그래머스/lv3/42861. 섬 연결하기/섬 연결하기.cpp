#include <bits/stdc++.h>

using namespace std;

vector<int> parent;

bool cmp (vector<int>a, vector<int>b){
    return a[2] < b[2];
}

int find_parent(int x){
    if (parent[x] == x)
        return x;
    else 
        return find_parent(parent[x]);
}

void uni(int x, int y){
    int px = find_parent(x);
    int py = find_parent(y);
    
    parent[px] = py;
    return;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    parent = vector<int>(n, 0);
    
    for (int i = 0 ; i < n ; i++){
        parent[i] = i;
    }

    sort(costs.begin(), costs.end(), cmp);
    
    for (auto i : costs){
        int x = find_parent(i[0]);
        int y = find_parent(i[1]);
        if (x == y)
            continue;
        answer += i[2];
        uni(x, y);
    }
    
    return answer;
}