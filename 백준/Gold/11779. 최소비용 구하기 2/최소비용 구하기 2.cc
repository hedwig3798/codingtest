#include <bits/stdc++.h>
#define INF INT_MAX / 2
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> busTable(n + 1);

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		busTable[from].push_back({ cost, to });
		// busTable[to].push_back({ cost, from });
	}

	int start, end;
	cin >> start >> end;

	vector<int> dik(n + 1, INF);
	vector<int> pastPath(n + 1, 0);

	priority_queue<pair<int, int>> pq;
	pq.push({ 0 ,start });
	dik[start] = 0;

	for(;!pq.empty();) {
		int cNode = pq.top().second;
		int cCost = -pq.top().first;
		pq.pop();

		if (cCost > dik[cNode]) {
			continue;
		}

		for(auto &bus : busTable[cNode]) {
			int nNode = bus.second;
			int nCost = cCost + bus.first;

			if (nCost < dik[nNode]) {
				dik[nNode] = nCost;
				pq.push({ -nCost, nNode });
				pastPath[nNode] = cNode;
			}
		}
	}
	
	vector<int>path;
	int temp = end;
	for(;temp != start;) {
		path.push_back(temp);
		temp = pastPath[temp];
	}
	path.push_back(start);
	cout << dik[end] << '\n';
	cout << path.size() << '\n';
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << ' ';
	}

	return 0;
}