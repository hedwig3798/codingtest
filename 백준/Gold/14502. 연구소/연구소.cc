#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x, y;
	int answer = 0;
	
	cin >> x >> y;
	vector<vector<int>> board(x, vector<int>(y, 0));
	

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < x * y; i++) {
		if (board[i/y][i%y] != 0)
			continue;
		board[i / y][i % y] = 1;

		for (int j = 0; j < x * y; j++) {
			if (board[j / y][j % y] != 0 || i == j)
				continue;
			board[j / y][j % y] = 1;

			for (int k = 0; k < x * y; k++) {
				if (board[k / y][k % y] != 0 || k == j || k == i)
					continue;
				board[k / y][k % y] = 1;

				vector<vector<int>> copy_board = board;

				queue<pair<int, int>> q;
				for (int xx = 0; xx < x; xx++) {
					for (int yy = 0; yy < y; yy++) {
						if (copy_board[xx][yy] == 2) {
							q.push({xx, yy});
						}
					}
				}
				
				for (; !q.empty();) {
					pair<int, int> now = q.front();
					q.pop();

					if (!(now.first == 0) && copy_board[now.first-1][now.second] == 0) {
						copy_board[now.first - 1][now.second] = 2;
						q.push({ now.first-1, now.second });
					}
					if (!(now.first == x-1) && copy_board[now.first + 1][now.second] == 0) {
						copy_board[now.first + 1][now.second] = 2;
						q.push({ now.first+1, now.second });
					}
					if (!(now.second == 0) && copy_board[now.first][now.second-1] == 0) {
						copy_board[now.first][now.second-1] = 2;
						q.push({ now.first, now.second-1 });
					}
					if (!(now.second == y-1) && copy_board[now.first][now.second+1] == 0) {
						copy_board[now.first][now.second+1] = 2;
						q.push({ now.first, now.second+1 });
					}
				}
				int count = 0;
				for (int i = 0; i < x; i++) {
					for (int j = 0; j < y; j++) {
						if (copy_board[i][j] == 0) {
							count++;
						}
					}
				}

				answer = max(answer, count);

				board[k / y][k % y] = 0;
			}
			board[j / y][j % y] = 0;
		}
		board[i / y][i % y] = 0;
	}
	cout << answer;
	return 0;
}