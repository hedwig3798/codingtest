#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int r, c, d;
	cin >> r >> c >> d;

	vector<vector<int>>board(n, vector<int>(m, 0));
	pair<int, int> now = { r, c };
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (;;) {

		if (board[now.first][now.second] == 0) {
			board[now.first][now.second] = 2;
			answer++;
		}

		if (board[now.first - 1][now.second] != 0 && board[now.first][now.second + 1] != 0 &&
			board[now.first + 1][now.second] != 0 && board[now.first][now.second - 1] != 0) {
		
			if (d == 0) {
				now = { now.first + 1, now.second };
			}
			if (d == 1) {
				now = { now.first, now.second - 1 };
			}
			if (d == 2) {
				now = { now.first - 1, now.second };
			}
			if (d == 3) {
				now = { now.first, now.second + 1 };
			}

			if (now.first < 0 || now.first > n - 1 || now.second < 0 || now.second > m - 1 || board[now.first][now.second] == 1)
				break;
			continue;
		}
		
		for (int i = 0; i < 4; i++) {
			d--;
			if (d < 0)
				d = 3;

			if (d == 0 && now.first > 0 && board[now.first - 1][now.second] == 0) {
				now = { now.first - 1, now.second };
				break;
			}
			if (d == 1 && now.second < m-1 && board[now.first][now.second + 1] == 0) {
				now = { now.first, now.second+1 };
				break;
			}
			if (d == 2 && now.first < n-1 && board[now.first + 1][now.second] == 0) {
				now = { now.first + 1, now.second };
				break;
			}
			if (d == 3 && now.second > 0 && board[now.first][now.second - 1] == 0) {
				now = { now.first, now.second-1 };
				break;
			}
		}

	}

	cout << answer;
	return 0;
} 