#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	
	for (int i = 0; i < t; i++) {
		int m, n, k;
		cin >> m >> n >> k;
		vector<vector<bool>> cavage(n, vector<bool>(m, false));

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			cavage[y][x] = true;
		}
		int answer = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (cavage[j][k]) {
					queue<pair<int, int>> q;
					q.push({ j, k });
					answer++;
					cavage[j][k] = false;
					for (; !q.empty();) {
						pair<int, int> now = q.front();
						q.pop();

						if (now.first > 0 && cavage[now.first - 1][now.second]) {
							q.push({ now.first - 1, now.second });
							cavage[now.first - 1][now.second] = false;
						}
						if (now.first < n - 1 && cavage[now.first + 1][now.second]) {
							q.push({ now.first + 1, now.second });
							cavage[now.first + 1][now.second] = false;
						}
						if (now.second > 0 && cavage[now.first][now.second - 1]) {
							q.push({ now.first, now.second - 1 });
							cavage[now.first][now.second - 1] = false;
						}
						if (now.second < m - 1 && cavage[now.first][now.second + 1]) {
							q.push({ now.first, now.second + 1 });
							cavage[now.first][now.second + 1] = false;
						}
					}
				}
			}
		}
		cout << answer << "\n";

	}



	return 0;
} 