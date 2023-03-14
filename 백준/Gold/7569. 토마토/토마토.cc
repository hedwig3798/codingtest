#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m, n, h;
	cin >> m >> n >> h;

	vector<vector<vector<int>>> board(h, vector<vector<int>>(n, vector<int>(m, 0)));
	vector<vector<vector<int>>> dis(h, vector<vector<int>>(n, vector<int>(m, 0)));

	int able_tomato = 0;
	queue <vector<int>> q;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) {
					able_tomato++;
					q.push({ i, j, k });
				}
				else if (board[i][j][k] == 0) {
					dis[i][j][k] = INT_MAX / 2;
					able_tomato++;
				}

			}
		}
	}
	
	for (;!q.empty();) {
		vector<int> now = q.front();
		q.pop();
		
		int nh = now[0], nx = now[1], ny = now[2];
		int nowdis = dis[nh][nx][ny] + 1;
		able_tomato--;

		// h 에 대한 탐색
		if (nh > 0 && board[nh-1][nx][ny] == 0) {
			board[nh - 1][nx][ny] = 1;
			dis[nh - 1][nx][ny] = min(dis[nh - 1][nx][ny], nowdis);
			q.push({ nh - 1, nx, ny });
		}
		if (nh < h-1 && board[nh + 1][nx][ny] == 0) {
			board[nh + 1][nx][ny] = 1;
			dis[nh + 1][nx][ny] = min(dis[nh + 1][nx][ny], nowdis);
			q.push({ nh + 1, nx, ny });
		}

		// x 에 대한 탐색
		if (nx > 0 && board[nh][nx - 1][ny] == 0) {
			board[nh][nx - 1][ny] = 1;
			dis[nh][nx - 1][ny] = min(dis[nh][nx - 1][ny], nowdis);
			q.push({ nh, nx - 1, ny });
		}
		if (nx < n - 1 && board[nh][nx + 1][ny] == 0) {
			board[nh][nx + 1][ny] = 1;
			dis[nh][nx + 1][ny] = min(dis[nh][nx + 1][ny], nowdis);
			q.push({ nh, nx + 1, ny });
		}

		// y 에 대한 탐색
		if (ny > 0 && board[nh][nx][ny - 1] == 0) {
			board[nh][nx][ny - 1] = 1;
			dis[nh][nx][ny - 1] = min(dis[nh][nx][ny - 1], nowdis);
			q.push({ nh, nx, ny - 1 });
		}
		if (ny < m-1 && board[nh][nx][ny+1] == 0) {
			board[nh][nx][ny + 1] = 1;
			dis[nh][nx][ny + 1] = min(dis[nh][nx][ny + 1], nowdis);
			q.push({ nh, nx, ny + 1 });
		}

	}

	if (able_tomato > 0)
		cout << -1;
	else {
		int result = 0;
		for (auto d : dis) {
			for (auto k : d) {
				result = max(*max_element(k.begin(), k.end()), result);
			}
			
		}
		cout << result;
	}

	return 0;
}