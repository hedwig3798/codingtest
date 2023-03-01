#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    // 합을 저장할 벡터
    vector<int>suma (money.size(), 0);
    vector<int>sumb (money.size(), 0);
    
    // 첫 집을 터는 경우
    suma[0] = money[0];
    // 두번째 집을 털지 못한다
    suma[1] = money[0];
    // 마지막 집을 털지 못하므로 -1 까지만 순회
    for (int i = 2 ; i < money.size()-1 ; i++){
        // 현재 위치의 집을 터는것이 이득인지 아닌지
        suma[i] = max(suma[i-1], suma[i-2] + money[i]);
    }
    
    // 첫 집을 털지 않는 경우
    sumb[0] = 0;
    sumb[1] = money[1];
    for (int i = 2 ; i < money.size() ; i++){
        sumb[i] = max(sumb[i-1], sumb[i-2] + money[i]);
    }
    
    // 두 경우에서 가장 큰 값만 
    return max(*max_element(suma.begin(), suma.end()) , *max_element(sumb.begin(), sumb.end()));;
}
