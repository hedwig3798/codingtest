#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int standard;

bool cmp (vector<int> a, vector<int> b){
    if (a[standard] == b[standard]){
        return a[0] > b[0];
    }
    return a[standard] < b[standard];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    standard = col-1;
    
    sort(data.begin(), data.end(), cmp);
    
    for (int i = row_begin-1; i < row_end ; i ++){
        int sum = 0;

        for (int j : data[i]){
            sum += j % (i+1);
        }
        answer = answer ^ sum;
    }
    
    return answer;
}