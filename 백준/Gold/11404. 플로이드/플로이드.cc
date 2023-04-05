#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> city(n + 1, vector<int>(n + 1, INT_MAX / 2));

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		city[from][to] = min(cost, city[from][to]);
	}

	for (int i = 0; i < n+1; i++) {
		city[i][i] = 0;
	}

	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < n+1; j++) {
			for (int k = 1; k < n+1; k++) {
				city[j][k] = min(city[j][k], city[j][i] + city[i][k]);
			}
		}
	}

	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < n+1; j++) {
			if (city[i][j] == INT_MAX/2 || i == j){
				cout << 0 << ' ';
			}
			else {
				cout << city[i][j] << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}