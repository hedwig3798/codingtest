#include <bits/stdc++.h>
#define INF 1e9

using namespace std;


int main()
{
	ios::sync_with_stdio(false);  cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> campus(n);
	pair<int, int> doyun;
	for (int i = 0; i < n; i++)
	{
		cin >> campus[i];
		for (int j = 0; j < m; j++)
		{
			if (campus[i][j] == 'I')
			{
				doyun = make_pair(i, j);
			}
		}
	}

	int result = 0;
	queue<pair<int, int>> q;
	q.push(doyun);

	vector<vector<bool>> isVisit(n, vector<bool>(m, false));
	isVisit[doyun.first][doyun.second] = true;

	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };

	while (!q.empty())
	{
		auto now = q.front();
		q.pop();

		int cx = now.first;
		int cy = now.second;

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			{
				continue;
			}
			if (campus[nx][ny] == 'X')
			{
				continue;
			}
			if (isVisit[nx][ny])
			{
				continue;
			}
			if (campus[nx][ny] == 'P')
			{
				result++;
			}
			isVisit[nx][ny] = true;
			q.push(make_pair(nx, ny));

		}
	}

	if (result == 0)
	{
		cout << "TT";
	}
	else
	{
		cout << result;
	}

	return 0;
}