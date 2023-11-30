#include <bits/stdc++.h>
#define INF 1e9

using namespace std;


int main()
{
	ios::sync_with_stdio(false);  cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> board(n, vector<int>(m, 0));
	vector<vector<int>> result(n, vector<int>(m, 0));

	pair<int, int> startPoint;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				startPoint = make_pair(i, j);
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(startPoint);

	int dx[] = { 1, 0, -1, 0 };
	int dy[] = { 0, 1, 0, -1 };

	while (!q.empty())
	{
		auto now = q.front();
		int nowx = now.first;
		int nowy = now.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextx = nowx + dx[i];
			int nexty = nowy + dy[i];

			if (nextx < 0 || nexty < 0 || nextx >= n || nexty >= m)
			{
				continue;
			}
			if (board[nextx][nexty] == 0)
			{
				continue;
			}
			if (result[nextx][nexty] != 0)
			{
				continue;
			}
			result[nextx][nexty] = result[nowx][nowy] + 1;
			q.push({ nextx , nexty });
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0 || board[i][j] == 2)
			{
				cout << "0 ";
			}
			else if (board[i][j] == 1 && result[i][j] == 0)
			{
				cout << "-1 ";
			}
			else
			{
				cout << result[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}