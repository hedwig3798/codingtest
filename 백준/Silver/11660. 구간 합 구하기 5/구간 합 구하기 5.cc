#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			int temp;
			cin >> temp;

			board[i][j] = temp + board[i - 1][j] + board[i][j - 1] - board[i-1][j-1];
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int sum = board[x2][y2] - board[x2][y1 - 1] - board[x1 - 1][y2] + board[x1 - 1][y1 - 1];
		cout << sum << '\n';
	}

	return 0;
}