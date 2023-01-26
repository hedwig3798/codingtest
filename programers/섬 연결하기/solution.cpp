#include <bits/stdc++.h>

using namespace std;
// Union-Find를 위한 벡터
vector<int> parent;

// 정렬 함수
bool cmp (vector<int>a, vector<int>b){
    return a[2] < b[2];
}

// Union-Find 함수
int find_parent(int x){
    if (parent[x] == x)
        return x;
    else 
        return find_parent(parent[x]);
}

// Union-Find를 위한 합 함수
void uni(int x, int y){
    int px = find_parent(x);
    int py = find_parent(y);
    
    parent[px] = py;
    return;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    // UnionFind를 위한 벡터 초기화
    parent = vector<int>(n, 0);
    for (int i = 0 ; i < n ; i++){
        parent[i] = i;
    }

    // 크루스칼 알고리즘을 적용하기 위해 정렬
    sort(costs.begin(), costs.end(), cmp);
    
    // 크루스칼 알고리즘 적용
    // 같은 union이라면 사이클이 되므로 무시 아니라면 거리값을 더함
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
