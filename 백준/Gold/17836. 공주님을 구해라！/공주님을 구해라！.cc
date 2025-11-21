#include <bits/stdc++.h>
#include <unordered_set>

int castle[101][101] = { 0, };

int N, M, T;

int dx[] = { 1, 0 ,-1, 0 };
int dy[] = { 0, 1 ,0, -1 };

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> M >> T;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::cin >> castle[i][j];
		}
	}

	std::queue<std::pair<int, int>> q;
	std::vector<std::vector<int>> isVisit(N, std::vector<int>(M, INT_MAX));
	q.push({ 0, 0 });
	isVisit[0][0] = 0;
	int ans = INT_MAX;

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
				|| ny >= M
				|| INT_MAX != isVisit[nx][ny]
				|| 1 == castle[nx][ny]
				)
			{
				continue;
			}

			isVisit[nx][ny] = isVisit[cx][cy] + 1;
			if (castle[nx][ny] == 2)
			{
				ans = std::min(ans, isVisit[nx][ny] + N - nx + M - ny - 2);
			}

			q.push({ nx, ny });
		}
	}

	if (ans > T 
		&& isVisit[N - 1][M - 1] > T)
		
	{
		std::cout << "Fail";
	}
	else
	{
		std::cout << std::min(isVisit[N - 1][M - 1], ans);
	}

	return 0;
}