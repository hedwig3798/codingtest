#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<string> board(n);

	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	vector<int> area;

	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] != '0') {
				queue<pair<int, int>> q;
				q.push({ i, j });
				board[i][j] = '0';

				int count = 0;
				int x[4] = { 1, 0, -1, 0 };
				int y[4] = { 0, 1, 0, -1 };
				for (; !q.empty();) {
					count++;
					pair<int, int> now = q.front();
					q.pop();

					for (int i = 0; i < 4; i++) {
						if (now.first + x[i] >= 0 &&
							now.first + x[i] < n &&
							now.second + y[i] >= 0 &&
							now.second + y[i] < n &&
							board[now.first + x[i]][now.second + y[i]] != '0') {
							
							q.push({ now.first + x[i], now.second + y[i] });
							board[now.first + x[i]][now.second + y[i]] = '0';
						}
					}
				}
				area.push_back(count);
			}
		}
	}
	cout << area.size() << '\n';
	sort(area.begin(), area.end());
	for (auto a : area) {
		cout << a << '\n';
	}
	return 0;
} 