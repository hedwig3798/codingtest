#include <bits/stdc++.h>

using namespace std;

void PrintQTree(vector<string> &board, pair<int, int>start, int size) {
	
	if (size == 1) {
		cout << board[start.first][start.second];
		return;
	}

	bool isSame = true;
	char now = board[start.first][start.second];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i + start.first][j + start.second] != now) {
				isSame = false;
				break;
			}
		}
		if (!isSame)
			break;
	}

	if (isSame) {
		cout << now;
		return;
	}
	cout << '(';
	PrintQTree(board, start, size / 2);
	PrintQTree(board, { start.first, start.second + (size / 2) }, size / 2);
	PrintQTree(board, { start.first + (size / 2) , start.second }, size / 2);
	PrintQTree(board, { start.first + (size / 2), start.second + (size / 2) }, size / 2);
	cout << ')';
	return;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<string> board(n);

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	PrintQTree(board, { 0, 0 }, n);

	return 0;
} 