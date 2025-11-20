#include <bits/stdc++.h>
#include <unordered_set>

int N, M;

std::vector<std::vector<int>> paper;
std::vector<std::vector<bool>> isVisit;

int ans = 0;

int dx[] = { 0, 1, -1, 0 };
int dy[] = { 1, 0, 0, -1 };

void DFS(int _x, int _y, int _depth, int _sum)
{
	if (_depth == 4)
	{
		ans = std::max(ans, _sum);
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int nx = _x + dx[i];
		int ny = _y + dy[i];

		if (nx < 0
			|| ny < 0
			|| nx >= N
			|| ny >= M
			|| true == isVisit[nx][ny]
			)
		{
			continue;
		}

		_sum += paper[nx][ny];
		isVisit[nx][ny] = true;
		DFS(nx, ny, _depth + 1, _sum);
		isVisit[nx][ny] = false;
		_sum -= paper[nx][ny];
	}
}

void woo(int _x, int _y)
{
	std::vector<int> nums;
	for (int i = 0; i < 4; ++i)
	{
		int nx = _x + dx[i];
		int ny = _y + dy[i];

		if (nx < 0
			|| ny < 0
			|| nx >= N
			|| ny >= M
			)
		{
			continue;
		}

		nums.push_back(paper[nx][ny]);
	}

	if (3 == nums.size())
	{
		int sum = paper[_x][_y] + nums[0] + nums[1] + nums[2];
		ans = std::max(ans, sum);
	}

	if (4 == nums.size())
	{
		std::sort(nums.begin(), nums.end());
		int sum = paper[_x][_y] + nums[1] + nums[2] + nums[3];
		ans = std::max(ans, sum);
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> M;

	paper = std::vector<std::vector<int>>(N, std::vector<int>(M));
	isVisit = std::vector<std::vector<bool>>(N, std::vector<bool>(M, false));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::cin >> paper[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			DFS(i, j, 0, 0);
			woo(i, j);
			// isVisit[i][j] = true;
		}
	}

	std::cout << ans;

	return 0;
}