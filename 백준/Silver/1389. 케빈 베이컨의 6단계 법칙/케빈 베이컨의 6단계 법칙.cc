#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n, vector<int>(n, INT_MAX/2 - 1));

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		graph[a - 1][b - 1] = 1;
		graph[b - 1][a - 1] = 1;
	}

	for (int i = 0; i < n; i++) {
		graph[i][i] = 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}
	pair<int, int> answer = { 0, INT_MAX / 2 };
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += graph[i][j];
		}
		if (sum < answer.second) {
			answer = { i + 1, sum };
		}
	}
	cout << answer.first;
	return 0;
} 