#include <bits/stdc++.h>
using namespace std;


vector<int> dik(vector<vector<pair<int, int>>> &graph, int start, int size) {
	vector<int> result(size + 1, INT_MAX / 2);

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	result[start] = 0;

	for (; !pq.empty();) {
		int cDis = -pq.top().first;
		int cNode = pq.top().second;
		pq.pop();
		if (cDis > result[cNode])
			continue;

		for (auto g : graph[cNode]) {
			int nDis = g.first + cDis;
			int nNode = g.second;

			if (nDis < result[nNode]) {
				result[nNode] = nDis;
				pq.push({ -nDis, nNode });
			}
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int v, e;
	cin >> v >> e;

	int start;
	cin >> start;

	vector<vector<pair<int ,int>>> graph(v + 1);

	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		graph[from].push_back({ cost, to });
	}

	vector<int> d = dik(graph, start, v);

	for (int i = 1; i < v + 1; i++) {
		if (d[i] >= INT_MAX / 2)
			cout << "INF\n";
		else
		
		cout << d[i] << '\n';
	}
	
	return 0;
} 