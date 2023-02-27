#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue <int, vector<int>, greater<int>> min_h;
    priority_queue <int, vector<int>, less<int>> max_h;
    int size = 0;
    
    for (auto i : operations){
        if (i[0] == 'I'){
            string s = i.substr(2);
            int number = stoi(s);
            max_h.push(number);
            min_h.push(number);
            size++;
        }
        else if (size == 0){
            continue;
        }
        else if (i == "D 1"){
            max_h.pop();
            size--;
        }
        else if (i == "D -1"){
            min_h.pop();
            size--;
        }
        
        if (size == 0){
            while(!max_h.empty()) max_h.pop();
            while(!min_h.empty()) min_h.pop();
        }
    }
    
    if (size == 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(max_h.top());
        answer.push_back(min_h.top());
    }
    
    
    return answer;
}