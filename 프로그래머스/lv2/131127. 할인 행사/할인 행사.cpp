#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    map<string, int> which;
    map<string, int> w;
    
    for (int i = 0; i < want.size(); i++){
        which.insert(pair(want[i], number[i]));
    }
    
    for (int i = 0; i < discount.size() - 9; i ++){
        if (i == 0){
            for (int j = 0; j < 10; j++){
                if (w.find(discount[j]) == w.end()){
                    w.insert(pair(discount[j], 1));
                }
                else {
                    w[discount[j]]++;
                }
            }
        }
        else {
            w[discount[i-1]]--;
            if (w[discount[i-1]] == 0){
                w.erase(discount[i-1]);
            }
            
            if (w.find(discount[i+9]) == w.end()){
                w.insert(pair(discount[i+9], 1));
            }
            else {
                w[discount[i+9]]++;
            } 
        }
        // printf("%s\n", discount[i+9].c_str());
        // for (auto temp: w){
        //     printf("%d %s", i, temp.first.c_str());
        //     printf(" %d\n", temp.second);
        // }
        // printf("----\n");
        
        int check = 1;
        for (auto k: which){
            if (w.find(k.first) == w.end()){
                check = 0;
                break;
            }
            else{
                if (w[k.first] < k.second){
                    check = 0;
                    break;
                }
            }
        }
        
        if (check == 1){
            answer++;
        }
        
        
    }
    
    return answer;
}