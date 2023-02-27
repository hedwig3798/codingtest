#include <bits/stdc++.h>
const int INF = 987654321;

using namespace std;

void rotate(vector<vector<int>> &key){
    vector<vector<int>> temp = key;
    
    for (int i = 0 ; i < key.size() ; i++){
        for (int j = 0 ; j < key.size() ; j++){
            key[i][j] = temp[key.size()-j-1][i];
        }
    }
    return;
}

bool check(int check_lock[][60], int n){
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            if (check_lock[i + n - 1][j + n - 1] == 1)
                continue;
            else
                return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int check_lock [60][60] = {0, };
    fill(&check_lock[0][0], &check_lock[59][60], 1);
    
    int kn = key.size();
    int ln = lock.size();
    
    for (int i = 0 ; i < ln ; i++){
        for (int j = 0 ; j < ln ; j++){
            check_lock[i + ln - 1][j + ln - 1] = lock[i][j];
        }
    }
    
    
    for (int k = 0 ; k < 4 ; k++){
        rotate(key);
        
        for (int lx = 0 ; lx < ln*2 + 1 ; lx++){
            for (int ly = 0 ; ly < ln*2 + 1 ; ly++){
                
                for (int kx = 0 ; kx < kn ; kx++){
                    for (int ky = 0 ; ky < kn ; ky++){
                            check_lock[lx + kx][ly + ky] += key[kx][ky];
                    }
                }
                if (check(check_lock, ln))
                    return true;
                
                for (int kx = 0 ; kx < kn ; kx++){
                    for (int ky = 0 ; ky < kn ; ky++){
                            check_lock[lx + kx][ly + ky] -= key[kx][ky];
                    }
                }
            }
        }
    }
    
    return false;;
}