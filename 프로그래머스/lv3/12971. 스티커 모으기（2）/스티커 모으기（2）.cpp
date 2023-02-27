#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    vector<int>suma (sticker.size(), 0);
    vector<int>sumb (sticker.size(), 0);
    suma[0] = sticker[0];
    suma[1] = sticker[0];
    
    for (int i = 2; i < sticker.size()-1 ; i++){
        suma[i] = max(suma[i-1], suma[i-2] + sticker[i]);
    }
    
    sumb[0] = 0;
    sumb[1] = sticker[1];
    for (int i = 2; i < sticker.size() ; i++){
        sumb[i] = max(sumb[i-1], sumb[i-2] + sticker[i]);
    }
    
    return max(*max_element(suma.begin(), suma.end()) , *max_element(sumb.begin(), sumb.end()));
}