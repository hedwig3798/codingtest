#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m, v;
	cin >> n >> m >> v;

	vector<vector<int>> graph(n + 1);
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	
	for (auto& g : graph) {
		sort(g.begin(), g.end(), greater<int>());
	}
	vector<bool> isVisitDFS(n + 1, false);
	stack<int> s;
	s.push(v);
	for (; !s.empty();) {
		int now = s.top();
		s.pop();
		if (!isVisitDFS[now]) {
			isVisitDFS[now] = true;
			cout << now << ' ';
			for (auto g : graph[now]) {
				s.push(g);
			}
		}
	}

	cout << '\n';

	for (auto& g : graph) {
		sort(g.begin(), g.end());
	}

	vector<bool> isVisitBFS(n + 1, false);
	queue<int> q;
	q.push(v);
	isVisitBFS[v] = true;
	for (; !q.empty();) {
		int now = q.front();
		q.pop();
		cout << now << ' ';
		for (auto g : graph[now]) {
			if (isVisitBFS[g])
				continue;
			isVisitBFS[g] = true;
			q.push(g);
		}
	}

	return 0;
} 