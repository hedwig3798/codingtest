#include <bits/stdc++.h>

using namespace std;

struct shark {
	pair<int, int> position;
	int size;
	int full;

	void checkSize() {
		if (size == full) {
			size++;
			full = 0;
		}
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;

	vector<vector<int>> ocean(n, vector<int>(n));
	shark s;

	int x[4] = { -1, 0, 0, 1 };
	int y[4] = { 0, -1, 1, 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ocean[i][j];
			if (ocean[i][j] == 9) {
				s.position = { i, j };
				s.size = 2;
				s.full = 0;
				ocean[i][j] = 0;
			}
		}
	}

	int answer = 0;
	for (;;) {
		bool isFind = false;

		queue<pair<int, int>> q;
		vector<vector<int>> isVisit(n, vector<int>(n, -1));
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		q.push(s.position);
		isVisit[s.position.first][s.position.second] = 0;
		for (; !q.empty();) {
			pair<int, int> now = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int row = now.first + x[i];
				int col = now.second + y[i];
				if (row >= 0 && row <= n - 1 && col >= 0 && col <= n - 1) {
					if (ocean[row][col] <= s.size && isVisit[row][col] == -1 && !isFind) {
						pq.push({ row, col });
						isVisit[row][col] = isVisit[now.first][now.second] + 1;
					}
				}
			}

			if (q.empty()) {
				for (; !pq.empty();) {
					if (ocean[pq.top().first][pq.top().second] < s.size && ocean[pq.top().first][pq.top().second] != 0) {
						isFind = true;
						s.position = pq.top();
						s.full++;
						s.checkSize();
						ocean[pq.top().first][pq.top().second] = 0;
						answer += isVisit[pq.top().first][pq.top().second];
						break;
					}
					q.push(pq.top());
					pq.pop();
				}
			}
			if (isFind)
				break;
		}
		if (!isFind)
			break;
	}
	cout << answer;
	return 0;
} 