#include <bits/stdc++.h>
using namespace std;

int countRegion(int n, vector<vector<bool>> &isVisit, vector<string> &board) {
	int normal = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!isVisit[i][j]) {
				normal++;
				char now = board[i][j];
				queue<pair<int, int>> q;
				q.push({ i, j });
				isVisit[i][j] = true;

				for (; !q.empty();) {
					pair<int, int> nnow = q.front();
					q.pop();
					int x = nnow.first, y = nnow.second;
					

					if (x > 0 && board[x - 1][y] == now && !isVisit[x - 1][y]) {
						q.push({ x - 1, y });
						isVisit[x-1][y] = true;
					}
					if (x < n - 1 && board[x + 1][y] == now && !isVisit[x + 1][y]) {
						q.push({ x + 1, y });
						isVisit[x+1][y] = true;
					}
					if (y > 0 && board[x][y - 1] == now && !isVisit[x][y - 1]) {
						q.push({ x, y - 1 });
						isVisit[x][y-1] = true;
					}
					if (y < n - 1 && board[x][y + 1] == now && !isVisit[x][y + 1]) {
						q.push({ x, y + 1 });
						isVisit[x][y+1] = true;
					}
				}
			}
		}
	}
	return normal;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<string> board(n);
	vector<vector<bool>> isVisit(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	int normal = 0;
	int cLess = 0;

	normal = countRegion(n, isVisit, board);

	for (auto& i : board) {
		for (auto& j : i) {
			if (j == 'G') {
				j = 'R';
			}
		}
	}

	isVisit.clear();
	isVisit = vector<vector<bool>>(n, vector<bool>(n, false));

	cLess = countRegion(n, isVisit, board);

	cout << normal << ' ' << cLess;

	return 0;
}