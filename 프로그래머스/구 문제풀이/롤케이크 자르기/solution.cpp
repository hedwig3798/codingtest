#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    map<int,int> top;
    map<int,int> sec;
    
    for (int i : topping){
        if (top.find(i) == top.end()){
            top.insert(pair<int, int>(i, 1));
        }
        else{
            top[i] += 1;
        }
    }
    
    for (int i : topping){
        if (top.find(i) == top.end()){
            break;
        }
        else {
            if (sec.find(i) == sec.end()){
                sec.insert(pair<int, int>(i, 1));
            }
            else{
                sec[i] += 1;
            }
            top[i] -= 1;
            if (top[i] == 0){
                top.erase(i);
            }
        }

        if (top.size() == sec.size()){
            answer++;
        }
    }

    return answer;
}
