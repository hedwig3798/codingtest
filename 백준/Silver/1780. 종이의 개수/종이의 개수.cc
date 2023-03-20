#include <bits/stdc++.h>

using namespace std;

void division(vector<vector<int>>& board, int& zero, int& one, int& minus, pair<int, int> start, int size) {
	int now = board[start.first][start.second];
	bool div = false;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (now != board[i + start.first][j + start.second]) {
				div = true;
				break;
			}
		}
		if (div)
			break;
	}

	if (div) {
		size /= 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				division(board, zero, one, minus, { start.first + size * i, start.second + size * j }, size);
			}
		}
	}
	else {
		if (now == 0)
			zero++;
		else if (now == 1)
			one++;
		else if (now == -1)
			minus++;
		return;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> board(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;

			board[i][j] = a;
		}
	}
	int zero = 0;
	int one = 0;
	int minus = 0;

	division(board, zero, one, minus, { 0, 0 }, n);

	cout << minus << '\n' << zero << '\n' << one;

	return 0;
} 