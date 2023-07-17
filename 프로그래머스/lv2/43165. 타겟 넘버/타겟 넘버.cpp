#include <string>
#include <vector>

using namespace std;

int answer = 0;

void DFS(vector<int>& numbers, int target, int depth, int now)
{
    if (depth == numbers.size()){
        if(now == target)
            answer++;
        return;
    }
    
    DFS(numbers, target, depth+1, now + numbers[depth]);
    DFS(numbers, target, depth+1, now - numbers[depth]);
}

int solution(vector<int> numbers, int target) {
   
    DFS(numbers, target, 0, 0);
    
    return answer;
}