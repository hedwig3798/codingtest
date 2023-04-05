#include <bits/stdc++.h>

using namespace std;

bool check(vector<int>& queen, int width, int depth) {
	if (depth == 0)
		return true;
	bool result = true;
	for (int i = 0; i < depth; i++) {
		if (queen[i] == width || abs(queen[i] - width) == abs(i - depth)) {
			result = false;
			break;
		}
	}

	return result;
}

void dfs(vector<int> &queen, int &count, int depth) {
	if (depth == queen.size()) {
		count++;
		return;
	}
		

	for (int i = 0; i < queen.size(); i++) {
		if (check(queen, i, depth)) {
			queen[depth] = i;
			dfs(queen, count, depth + 1);
			queen[depth] = -1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<int>queen(n, -1);
	int count = 0;

	dfs(queen, count, 0);

	cout << count;
	return 0;
} 