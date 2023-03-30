#include <bits/stdc++.h>
using namespace std;

void preorder(vector<int> &inorder, vector<int> &postorder, pair<int, int>inindex, pair<int, int> postindex, vector<int> &inorderIndex) {
	int totalSize = inindex.second - inindex.first + 1;
	if (totalSize == 1) {
		cout << inorder[inindex.first] << ' ';
		return;
	}
	if (totalSize == 0)
		return;
	int root = postorder[postindex.second];
	cout << root << ' ';

	int i = inorderIndex[root];

	preorder(inorder, postorder, { inindex.first, i - 1 }, { postindex.first,  postindex.first + (i - inindex.first) - 1}, inorderIndex);
	preorder(inorder, postorder, { i + 1, inindex.second }, { postindex.first + (i - inindex.first), postindex.second - 1 }, inorderIndex);

	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> inorder;
	vector<int> postorder;
	vector<int> inortderIndex(n+1, 0);

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		inorder.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		postorder.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		inortderIndex[inorder[i]] = i;
	}
	preorder(inorder, postorder, { 0, n - 1 }, { 0, n - 1 }, inortderIndex);

	return 0;
} 