#include <bits/stdc++.h>
using namespace std;

pair<int, int> dfs(vector<vector<pair<int, int>>> &tree, int now, int ver, vector<bool> &isVisit) {
	pair<int, int> result = { now, ver };
	isVisit[now] = true;

	for (auto t : tree[now]) {
		if (isVisit[t.first])
			continue;
		pair<int, int> temp = dfs(tree, t.first, ver + t.second, isVisit);
		if (result.second < temp.second) {
			result = temp;
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<pair<int ,int>>> tree (n+1);

	for (int i = 1; i <= n; i++) {
		int now;
		cin >> now;

		for (;;) {
			int node;
			cin >> node;
			if (node == -1)
				break;
			int ver;
			cin >> ver;

			tree[now].push_back({ node, ver });
		}
	}

	int answer = 0;
	vector<bool> isVisit(n + 1, false);
	pair<int, int> temp = dfs(tree, 1, 0, isVisit);
	isVisit = vector<bool>(n + 1, false);
	answer = dfs(tree, temp.first, 0, isVisit).second;

	cout << answer;
	return 0;
} 