#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, vector<int>> a, pair<int, vector<int>> b){
    if (a.second[1] > b.second[1])
        return true;
    else if (a.second[1] < b.second[1])
        return false;
    else {
        return a.second[0] < b.second[0];
    }
    
}

struct n{
    int num;
    int x;
    n *left;
    n *right;
};

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

void traversal(vector<vector<int>> &answer, n *node){
    answer[0].push_back(node->num);
    if (node->left != NULL){
        traversal(answer, node->left);
    }
    if (node->right != NULL){
        traversal(answer, node->right);
    }
    answer[1].push_back(node->num);
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    vector<pair<int, vector<int>>> node;
    vector<vector<int>> tree(nodeinfo.size() + 1);
    
    for (int i = 0 ; i < nodeinfo.size() ; i++){
        node.push_back({i+1, nodeinfo[i]});
    }
    
    sort(node.begin(), node.end(), cmp);
    
    n *root = new n();
    root->num = node[0].first;
    root->x = node[0].second[0];
    root->left = NULL;
    root->right = NULL;
    
    for (int i = 1 ; i < node.size() ; i++){
        n *temp = new n();;
        temp->num = node[i].first;
        temp->x = node[i].second[0];
        temp->left = NULL;
        temp->right = NULL;
        insert_node(root, temp);
    }
    
    traversal(answer, root);
    
    return answer;
}