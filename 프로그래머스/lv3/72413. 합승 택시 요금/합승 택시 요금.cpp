#include <bits/stdc++.h>

using namespace std;

int graph[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 3000000;
    
    fill(&graph[0][0], &graph[n][n], 3000000);
    
    for (auto f : fares){
        graph[f[0]][f[1]] = f[2];
        graph[f[1]][f[0]] = f[2];  
    }
    
    for (int i = 1 ; i < n+1 ; i++){
        graph[i][i] = 0;
    }
    
    for (int k = 1 ; k < n+1 ; k++){
        for (int i = 1 ; i < n+1 ; i++){
            for (int j = 1 ; j < n+1 ; j++){
                if (graph[j][i] > graph[i][k] + graph[k][j])
                    graph[j][i] = graph[i][k] + graph[k][j];
            }
        }
    }
    
    
    // for (int i = 1 ; i < n+1 ; i++){
    //     for (int j = 1 ; j < n+1 ; j++){
    //         cout << graph[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
    for (int i = 1 ; i < n+1 ; i++){
        int temp = graph[s][i];
        temp += graph[i][b];
        temp += graph[i][a];
        answer = min(answer, temp);
    }
    
    return answer;
}