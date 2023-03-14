#include <bits/stdc++.h>
using namespace std;

void punch(vector<vector<int>> &board, pair<int, int> start, int size) {

	if (size == 1)
		return;
	vector<pair<int, int>> mod9(9, { 0,0 });


	int ind = 0;
	for (int i = 0; i < size; i += size / 3) {
		for (int j = 0; j < size; j += size / 3) {
			mod9[ind] = { i + start.first ,j + start.second };
			ind++;
		}
	}

	for (int i = 0; i < 9; i++) {
		punch(board, mod9[i], size / 3);
	}
	

	for (int i = 0; i < size / 3; i++) {
		for (int j = 0; j < size / 3; j++) {
			board[mod9[4].first + i][mod9[4].second + j] = 0;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int x;
	cin >> x;

	vector<vector<int>> board(x, vector<int>(x, 1));

	punch(board, { 0,0 }, x);

	for (auto i : board) {
		for (auto j : i) {
			if (j == 1)
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}

	return 0;
}