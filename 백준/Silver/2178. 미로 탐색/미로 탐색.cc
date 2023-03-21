#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<string> board(n);
	vector<vector<int>> isVisit(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	isVisit[0][0] = 0;

	for (; !q.empty();) {
		pair<int, int> now = q.front();
		q.pop();

		if (now.first > 0 && board[now.first - 1][now.second] != '0' && isVisit[now.first - 1][now.second] == -1) {
			isVisit[now.first - 1][now.second] = isVisit[now.first][now.second] + 1;
			q.push({ now.first - 1 , now.second });
		}
		if (now.first < n - 1 && board[now.first + 1][now.second] != '0' && isVisit[now.first + 1][now.second] == -1) {
			isVisit[now.first + 1][now.second] = isVisit[now.first][now.second] + 1;
			q.push({ now.first + 1 , now.second });
		}
		if (now.second > 0 && board[now.first][now.second - 1] != '0' && isVisit[now.first][now.second - 1] == -1) {
			isVisit[now.first][now.second - 1] = isVisit[now.first][now.second] + 1;
			q.push({ now.first , now.second - 1 });
		}
		if (now.second < m - 1 && board[now.first][now.second + 1] != '0' && isVisit[now.first][now.second + 1] == -1) {
			isVisit[now.first][now.second + 1] = isVisit[now.first][now.second] + 1;
			q.push({ now.first , now.second + 1 });
		}
	}

	cout << isVisit[n - 1][m - 1] + 1;
	return 0;
} 