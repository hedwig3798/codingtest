#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> a;
    vector<int> cir;
    cir.insert(cir.end(), elements.begin(), elements.end());
    cir.insert(cir.end(), elements.begin(), elements.end());
    int sum = accumulate(elements.begin(), elements.end(), 0);

    for (int i = 1; i <= elements.size()/2; i++){
        
        for (int j = 1; j <= elements.size(); j++){   
            int temp = accumulate(cir.begin()+j, cir.begin()+j+i, 0);
            a.insert(temp); 
            a.insert(sum-temp); 
        }
    }
    answer = a.size()+1;
    return answer;
}
