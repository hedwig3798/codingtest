#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    
    vector<int>suma (money.size(), 0);
    vector<int>sumb (money.size(), 0);
    
    suma[0] = money[0];
    suma[1] = money[0];
    for (int i = 2 ; i < money.size()-1 ; i++){
        suma[i] = max(suma[i-1], suma[i-2] + money[i]);
    }
    
    sumb[0] = 0;
    sumb[1] = money[1];
    
    for (int i = 2 ; i < money.size() ; i++){
        sumb[i] = max(sumb[i-1], sumb[i-2] + money[i]);
    }
    
    
    return max(*max_element(suma.begin(), suma.end()) , *max_element(sumb.begin(), sumb.end()));;
}