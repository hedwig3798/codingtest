#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp (vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<int> c;
    
    sort(routes.begin(), routes.end(), cmp);
    
    for (auto r : routes){
        if (c.empty()){
            c.push_back(r[1]);
        }
        else if (c.back() >= r[0]){
            continue;
        }
        else {
            c.push_back(r[1]);
        }     
    }
    
    return c.size();
}