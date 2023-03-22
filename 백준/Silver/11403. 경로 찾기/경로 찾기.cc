#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;

	vector<vector<int>> board(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	vector<vector<int>> canVisit(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		vector<bool>isVisit(n, false);
		queue<int> q;

		q.push(i);
		for (; !q.empty();) {
			int now = q.front();
			q.pop();

			for (int j = 0; j < n; j++) {
				if (isVisit[j] || board[now][j] == 0)
					continue;

				isVisit[j] = true;
				q.push(j);
			}
		}

		for (int j = 0; j < n; j++) {
			if (isVisit[j]) {
				canVisit[i][j] = 1;
			}
		}
	}
	
	for (auto i : canVisit) {
		for (auto j : i) {
			cout << j << ' ';
		}
		cout << '\n';
	}

	return 0;
} 