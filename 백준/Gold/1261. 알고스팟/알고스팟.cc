#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int m, n;
	cin >> m >> n;

	vector<string> board;
	vector<vector<int>> cost(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		board.push_back(temp);
	}

	deque<pair<int, int>> d;
	d.push_back({ 0, 0 });
	cost[0][0] = 1;

	int dx[4] = { 0, -1, 0, 1 };
	int dy[4] = { 1, 0, -1, 0 };

	while (!d.empty())
	{
		pair<int, int> now = d.front();
		d.pop_front();

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> temp = { now.first + dx[i], now.second + dy[i] };

			if (temp.first < 0 || temp.first >= n || temp.second < 0 || temp.second >= m)
			{
				continue;
			}

			if (cost[temp.first][temp.second] != -1)
			{
				continue;
			}

			if (board[temp.first][temp.second] == '0')
			{
				cost[temp.first][temp.second] = cost[now.first][now.second];
				d.push_front(temp);
			}
			else if (board[temp.first][temp.second] == '1')
			{
				cost[temp.first][temp.second] = cost[now.first][now.second] + 1;
				d.push_back(temp);
			}
		}
	}
	cout << cost[n - 1][m - 1] - 1;
	return 0;
}