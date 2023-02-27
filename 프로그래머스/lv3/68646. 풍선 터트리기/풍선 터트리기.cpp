#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    vector<int> lmin(a.size());
    vector<int> rmin(a.size());
    if (a.size() == 1 || a.size() == 2)
        return a.size();
    
    int l = a[0];
    int r = a.back();
    
    for (int i = 0 ; i < a.size() ; i++){
        if (a[i] < l){
            l = a[i];
        }
        lmin[i] = l;
    }
    
    for (int i = a.size()-1 ; i >= 0 ; i--){
        if (a[i] < r){
            r = a[i];
        }
        rmin[i] = r;
    }
    // for (auto i : rmin){
    //     cout << i << ' ';
    // }
    // cout << endl;
    // for (auto i : lmin){
    //     cout << i << ' ';
    // }
    // cout << endl;
    
    for (int i = 1 ; i < a.size()-1 ; i++){
        
        if (!(a[i] > lmin[i-1] && a[i] > rmin[i+1]))
            answer++;
    }
    
    return answer+2;
}