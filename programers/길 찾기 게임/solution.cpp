#include <bits/stdc++.h>

using namespace std;

// 정렬 함수
// y축 기준으로 내림차순, 그 후 x축 기준으로 내림차순
bool cmp(pair<int, vector<int>> a, pair<int, vector<int>> b){
    if (a.second[1] > b.second[1])
        return true;
    else if (a.second[1] < b.second[1])
        return false;
    else {
        return a.second[0] < b.second[0];
    }
    
}

// 트리 노드
struct n{
    int num;
    int x;
    n *left;
    n *right;
};

// 트리 삽입
void insert_node(n *node, n *input){
    if (node->x > input->x){
        if (node->left == NULL) {
            node->left = input;
        }
        else {
            //cout << input->num << endl;
            insert_node(node->left , input);
        }      
    }
    else {
        if (node->right == NULL) {
            node->right = input;
        }
        else {
            insert_node(node->right , input);
        }  
    }
}

// 트리 순회
void traversal(vector<vector<int>> &answer, n *node){
    // 전위 순회
    answer[0].push_back(node->num);
    if (node->left != NULL){
        traversal(answer, node->left);
    }
    if (node->right != NULL){
        traversal(answer, node->right);
    }
    // 후위 순회
    answer[1].push_back(node->num);
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    // 정답 벡터의 크기를 미리 지정
    vector<vector<int>> answer(2);
    // 데이터 형식화
    vector<pair<int, vector<int>>> node;
    
    // 데이터 형식화
    for (int i = 0 ; i < nodeinfo.size() ; i++){
        node.push_back({i+1, nodeinfo[i]});
    }
    
    // 정렬
    sort(node.begin(), node.end(), cmp);
    
    // 루트 노드 만들기
    n *root = new n();
    root->num = node[0].first;
    root->x = node[0].second[0];
    root->left = NULL;
    root->right = NULL;
    
    // 트리 만들기
    for (int i = 1 ; i < node.size() ; i++){
        n *temp = new n();;
        temp->num = node[i].first;
        temp->x = node[i].second[0];
        temp->left = NULL;
        temp->right = NULL;
        insert_node(root, temp);
    }
    
    // 트리 
    traversal(answer, root);
    
    return answer;
}
