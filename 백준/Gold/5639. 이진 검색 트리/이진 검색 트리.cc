#include <bits/stdc++.h>

using namespace std;

struct node {
	int val;
	node* left;
	node* right;
};

void insert(node * root, node * input){
	if (root->val < input->val) {
		if (root->right == nullptr) {
			root->right = input;
			return;
		}
		insert(root->right, input);
	}
	else{
		if (root->left == nullptr) {
			root->left = input;
			return;
		}
		insert(root->left, input);
	}
	return;
}

void postorder(node * root){
	if (root->left != nullptr){
		postorder(root->left);
	}
	if (root->right != nullptr){
		postorder(root->right);
	}
	cout << root->val << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	node* root = new node;
	cin >> root->val;
	root->left = nullptr;
	root->right = nullptr;
	for(;;) {
		node* temp = new node;
		cin >> temp->val;
		if (cin.fail()) {
			break;
		}
		temp->left = nullptr;
		temp->right = nullptr;
		insert(root, temp);
		
	}

	postorder(root);

	return 0;
}