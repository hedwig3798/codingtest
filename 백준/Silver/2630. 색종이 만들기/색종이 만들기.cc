#include <bits/stdc++.h>

using namespace std;

void getCoutn(vector<vector<int>> &board, pair<int, int> start, int size, int &one, int &zero) {
	int now = board[start.first][start.second];
	bool isSame = true;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (now != board[i + start.first][j + start.second]) {
				isSame = false;
				break;
			}
		}
		if (!isSame)
			break;
	}

	if (isSame) {
		if (now == 0)
			zero++;
		else if (now == 1)
			one++;
		return;
	}
	int x[4] = { 0, 1, 0, 1 };
	int y[4] = { 0, 0, 1, 1 };

	for (int i = 0; i < 4; i++) {
		getCoutn(board, { start.first + ((size / 2) * x[i]) ,start.second + ((size / 2) * y[i]) }, size / 2, one, zero);
	}
	
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> board(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	int zero = 0;
	int one = 0;
	
	getCoutn(board, { 0, 0 }, n, one, zero);

	cout << zero << '\n' << one;

	return 0;
} 