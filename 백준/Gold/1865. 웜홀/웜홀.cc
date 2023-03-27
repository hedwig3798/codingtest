#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		int n, m, w;
		cin >> n >> m >> w;
		vector<int> distance(n + 1, INT_MAX/2);
		vector<bool> isvist(n + 1, false);
		vector<vector<int>> costs;
		for (int i = 0; i < m; i++) {
			int from, to, cost;
			cin >> from >> to >> cost;
			costs.push_back({ from, to, cost });
			costs.push_back({ to, from, cost });
		}

		for (int i = 0; i < w; i++) {
			int from, to, cost;
			cin >> from >> to >> cost;
			costs.push_back({ from, to, -cost });
		}

		isvist[0] = true;
		distance[0] = 0;
		for (int i = 1; i < isvist.size(); i++) {
			if (isvist[i])
				continue;
			else {
				distance[i] = 0;

				for (int k = 0; k < n; k++) {
					for (int j = 0; j < costs.size(); j++) {
						int start = costs[j][0];
						int end = costs[j][1];
						int how = costs[j][2];

						if (distance[start] != INT_MAX / 2) {
							distance[end] = min(distance[end], distance[start] + how);
							isvist[end] = true;
						}
					}
				}
			}
		}
		bool iscy = false;
		for (int i = 0; i < costs.size(); i++) {
			int start = costs[i][0];
			int end = costs[i][1];
			int how = costs[i][2];

			if (distance[end] > distance[start] + how) {
				cout << "YES\n";
				iscy = true;
				break;
			}
		}
		if (!iscy)
			cout << "NO\n";


	}
	
	return 0;
} 