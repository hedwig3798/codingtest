#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int x, y;
	cin >> y >> x;

	vector<vector<int>> board(x, vector<int>(y, -1));
	vector<vector<int>> dis(x, vector<int>(y, 0));
	int ableTomato = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				ableTomato++;
				dis[i][j] = INT_MAX/2;
			}
			else if (board[i][j] == 1) {
				q.push({ i, j });
				ableTomato++;
			}
		}
	}
	

	for (;!q.empty();) {
		pair<int, int> now = q.front();
		q.pop();
		ableTomato--;
		int nowdis = dis[now.first][now.second] + 1;

		if (now.first > 0 && board[now.first - 1][now.second] == 0) {
			board[now.first - 1][now.second] = 1;
			dis[now.first - 1][now.second] = min(dis[now.first - 1][now.second], nowdis);
			q.push({ now.first - 1, now.second });
		}
		if (now.first < x-1 && board[now.first + 1][now.second] == 0) {
			board[now.first + 1][now.second] = 1;
			dis[now.first + 1][now.second] = min(dis[now.first + 1][now.second], nowdis);
			q.push({ now.first + 1, now.second });
		}
		if (now.second > 0 && board[now.first][now.second - 1] == 0) {
			board[now.first][now.second - 1] = 1;
			dis[now.first][now.second - 1] = min(dis[now.first][now.second - 1], nowdis);
			q.push({ now.first, now.second - 1 });
		}
		if (now.second < y-1 && board[now.first][now.second + 1] == 0) {
			board[now.first][now.second + 1] = 1;
			dis[now.first][now.second + 1] = min(dis[now.first][now.second + 1], nowdis);
			q.push({ now.first, now.second + 1 });
		}

	}

	if (ableTomato > 0)
		cout << -1;
	else {
		int result = 0;
		for (auto d : dis) {
			result = max(*max_element(d.begin(), d.end()), result);
		}
		cout << result;
	}

	return 0;
}