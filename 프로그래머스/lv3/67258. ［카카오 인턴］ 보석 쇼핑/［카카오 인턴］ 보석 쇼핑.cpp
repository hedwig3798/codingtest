#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> all_j;
    map<string, int> part_j;
    
    int start = 0;
    int end  = 0;
    
    for (auto i : gems){
        all_j[i] += 1; 
    }
    
    answer.push_back(1);
    answer.push_back(gems.size());
    
    for (;end != gems.size() || start != gems.size();){
        if (part_j.size() != all_j.size() && end != gems.size()){
            part_j[gems[end]] += 1;
            end++;
        }
        
        else {
            part_j[gems[start]] -= 1;
            if (part_j[gems[start]] == 0){
                //cout << gems[start] << endl;
                part_j.erase(gems[start]);
            }
            
            start++;
        }
        if (answer[1] - answer[0] > end - start - 1 && part_j.size() == all_j.size()){
            answer[1] = end;
            answer[0] = start + 1;
            
        }
        //cout << start << ' ' << end << ' ' << part_j.size() << endl;
    }
    
    
    return answer;
}