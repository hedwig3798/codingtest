#include <string>
#include <vector>

using namespace std;

vector<int> answer(1, -1);
int max_s = 0;

void pprint(vector<int> temp){
    for (int t: temp){
        printf("%d ", t);
    }
    printf("\n");
}

bool is_low(vector<int> &answer, vector<int> &rion){
    for (int i = 10; i >=0; i--){
        if (answer[i] > rion[i]){
            return false;
        }
        else if (answer[i] < rion[i]){
            return true;
        }
    }
}

int get_score(vector<int> &rion, vector<int> &ap){
    int rs = 0;
    int as = 0;
    
    for (int i = 0; i < 11 ; i++){
        if (rion[i] > ap[i]){
            rs += 10 - i;
        }
        else if(ap[i] != 0){
            as += 10 - i;
        }
    }

    return rs - as;
}

void search(int index, int arrow, vector<int> &rion, vector<int> &ap){
    if (index == 11 || arrow == 0){
        int s = get_score(rion, ap);
        rion[10] += arrow;
        if (s > max_s && s > 0){
            max_s = s;
            answer = rion;
        }
        else if (s == max_s && is_low(answer, rion)){
            answer = rion;
        }
        rion[10] -= arrow;
        return;
    }
    
    else {
        if (arrow > ap[index]){
            rion[index] += ap[index]+1;
            search(index+1, arrow-ap[index]-1, rion, ap);
            rion[index] -= ap[index]+1;
        }
        search(index+1, arrow, rion, ap);
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> rion(11,0);
    search(0, n, rion, info);
    return answer;
}