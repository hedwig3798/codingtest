#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct n {
    int number;
    int count;
};

bool cmp(n a, n b){
    if (a.count == b.count){
        return a.number < b.number;
    }
    return a.count > b.count;
}

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    vector<n> numbers;
    
    for (int i = 0 ; i <= e ; i ++){
        n temp;
        temp.number = i;
        temp.count = 1; 
        numbers.push_back(temp);
    }
    
    for (int i = 2; i <= e; i++){
        for (int j = 1 ; j <= e/i ; j++){
            numbers[i*j].count++;
            // printf("%d, %d\n", i, j);
        }
        // printf("\n");
    }
    
    sort(numbers.begin(), numbers.end(), cmp);
    
    // for (n i : numbers){
    //     printf("%d, %d\n", i.number, i.count);
    // }
    
    for (int s : starts){
        for (int i = 0 ; i <= e ; i++){
            if (numbers[i].number >= s && numbers[i].number <= e){
                answer.push_back(numbers[i].number);
                break;
            }
        }
    }
    
    return answer;
}