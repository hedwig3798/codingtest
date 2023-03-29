#include <bits/stdc++.h>
using namespace std;

void bfs(vector<string> &graph, vector<vector<int>> &isVisit, pair<int, int> startingPoint) {
	queue<pair<int, int>> q;
	q.push(startingPoint);

	int x[4] = { 1, 0, -1, 0 };
	int y[4] = { 0, 1, 0, -1 };

	for (; !q.empty();) {
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			if (now.first + x[i] < 0 || now.first + x[i] > graph.size() - 1 ||
				now.second + y[i] < 0 || now.second + y[i] > graph[0].size() - 1) {
				continue;
			}
			if (isVisit[now.first + x[i]][now.second + y[i]] != -1)
				continue;

			isVisit[now.first + x[i]][now.second + y[i]] = isVisit[now.first][now.second] + 1;
			if (graph[now.first + x[i]][now.second + y[i]] == '0') {
				q.push({ now.first + x[i], now.second + y[i] });
			}

		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<string> graph(n);

	for (int i = 0; i < n; i++) {
		cin >> graph[i];
	}

	vector<vector<int>> startAtStart(n, vector<int>(m, -1));
	vector<vector<int>> startAtEnd(n, vector<int>(m, -1));

	startAtStart[0][0] = 0;
	startAtEnd[n - 1][m - 1] = 0;

	
	bfs(graph, startAtStart, { 0, 0 });
	bfs(graph, startAtEnd, { n - 1, m - 1 });

	int shortest = INT_MAX / 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (startAtStart[i][j] == -1 || startAtEnd[i][j] == -1)
				continue;
			shortest = min(shortest, startAtStart[i][j] + startAtEnd[i][j]);
		}
	}
	if (shortest == INT_MAX / 2)
		cout << -1;
	else
		cout << shortest + 1;

	return 0;
} 