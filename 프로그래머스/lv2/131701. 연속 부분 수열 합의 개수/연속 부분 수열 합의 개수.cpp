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
    //printf("%d %d\n\n", elements.size()/2, sum);
    for (int i = 1; i <= elements.size()/2; i++){
        
        for (int j = 1; j <= elements.size(); j++){   
            int temp = accumulate(cir.begin()+j, cir.begin()+j+i, 0);
            //printf("%d %d\n",temp, sum-temp);

            a.insert(temp); 
            //printf("-%d\n",temp);
            
            

            a.insert(sum-temp); 
            //printf("--%d %d %d\n",sum-temp, i, j);
            
        }
        //printf("\n");
        
        
    }
    answer = a.size()+1;
    return answer;
}