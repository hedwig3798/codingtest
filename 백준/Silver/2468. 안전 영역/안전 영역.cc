#include <bits/stdc++.h>
#include <unordered_set>

int N;
int city[100][100];
int hightCount[101] = { 0, };

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int ans = 1;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			std::cin >> city[i][j];
			hightCount[city[i][j]]++;
		}
	}

	for (int h = 1; h <= 100; ++h)
	{
		if (hightCount[h] == 0)
		{
			continue;
		}

		std::vector<std::vector<bool>> isVisit(N, std::vector<bool>(N, false));
		int count = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (city[i][j] <= h
					|| true == isVisit[i][j])
				{
					isVisit[i][j] = true;
					continue;
				}
				else
				{
					isVisit[i][j] = true;
					count++;
					std::queue<std::pair<int, int>> q;
					q.push({ i, j });
					while (false == q.empty())
					{
						std::pair<int, int> curr = q.front();
						q.pop();
						int cx = curr.first;
						int cy = curr.second;

						for (int i = 0; i < 4; ++i)
						{
							int nx = cx + dx[i];
							int ny = cy + dy[i];

							if (nx < 0
								|| ny < 0
								|| nx >= N
								|| ny >= N
								|| true == isVisit[nx][ny]
								)
							{
								continue;
							}

							isVisit[nx][ny] = true;
							if (city[nx][ny] > h)
							{
								q.push({ nx, ny });
							}

						}
					}
				}
			}
		}
		ans = std::max(ans, count);
	}

	std::cout << ans;

	return 0;
}