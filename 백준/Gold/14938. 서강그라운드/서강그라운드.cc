#include <bits/stdc++.h>
#define INF INT_MAX / 2
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m, r;
	cin >> n >> m >> r;

	vector<int> item(n + 1, 0);
	vector<vector<pair<int, int>>> graph(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}

	for (int i = 1; i <= r; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		graph[from].push_back({ cost, to });
		graph[to].push_back({ cost, from });
	}

	
	int answer = 0;

	for (int i = 1; i <= n; i++) {
		vector<int> pickable(n + 1, INF);
		priority_queue<pair<int, int>> pq;
		pq.push({ 0, i });
		pickable[i] = 0;
		for(;!pq.empty();) {
			int cNode = pq.top().second;
			int cCost = -pq.top().first;
			pq.pop();

			for(auto g : graph[cNode]) {
				int nNode = g.second;
				int nCost = g.first + cCost;

				if (nCost < pickable[nNode]) {
					pickable[nNode] = nCost;
					pq.push({ -nCost, nNode });
				}
			}
		}
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (pickable[i] <= m) {
				sum += item[i];
			}
		}
		answer = max(answer, sum);
	}

	cout << answer;
	
	return 0;
}