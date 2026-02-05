#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

#define MAX_N 100

int N, K, L;
int board[MAX_N][MAX_N] = { 0, };

// 0     1      2   3
// right, down, left, up
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int GetRight(int _dir)
{
	switch (_dir)
	{
	case 0:
		return 1;
	case 1:
		return 2;
	case 2:
		return 3;
	case 3:
		return 0;
	}

	return -1;
}

int GetLeft(int _dir)
{
	switch (_dir)
	{
	case 0:
		return 3;
	case 1:
		return 0;
	case 2:
		return 1;
	case 3:
		return 2;
	}

	return -1;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> K;
	for (int i = 0; i < K; ++i)
	{
		int x, y;
		std::cin >> x >> y;
		--x;
		--y;

		board[x][y] = 1;
	}

	std::cin >> L;
	int ans = 0;
	std::deque<std::pair<int, int>> snake;
	snake.push_back({ 0, 0 });
	board[0][0] = 2;
	int dir = 0;
	int time = 0;

	for (int i = 0; i < L; ++i)
	{
		int x;
		char c;
		std::cin >> x >> c;

		x = x - time;

		for (int j = 0; j < x; ++j)
		{
			ans++;
			auto head = snake.front();
			int hx = head.first;
			int hy = head.second;

			int nx = hx + dx[dir];
			int ny = hy + dy[dir];


			if (0 > nx
				|| 0 > ny
				|| nx >= N
				|| ny >= N
				|| 2 == board[nx][ny])
			{
				std::cout << ans;
				return 0;
			}

			if (1 != board[nx][ny])
			{
				auto tail = snake.back();
				int tx = tail.first;
				int ty = tail.second;
				board[tx][ty] = 0;
				snake.pop_back();
			}

			board[nx][ny] = 2;
			snake.push_front({ nx, ny });
		}

		time += x;

		switch (c)
		{
		case 'D':
		{
			dir = GetRight(dir);
			break;
		}
		case 'L':
		{
			dir = GetLeft(dir);
			break;
		}
		default:
			break;
		}
	}

	while (true)
	{
		ans++;
		auto& head = snake.front();
		int hx = head.first;
		int hy = head.second;

		int nx = hx + dx[dir];
		int ny = hy + dy[dir];


		if (0 > nx
			|| 0 > ny
			|| nx >= N
			|| ny >= N
			|| 2 == board[nx][ny])
		{
			std::cout << ans;
			return 0;
		}

		if (1 != board[nx][ny])
		{
			auto& tail = snake.back();
			int tx = tail.first;
			int ty = tail.second;
			board[tx][ty] = 0;
			snake.pop_back();
		}

		board[nx][ny] = 2;
		snake.push_front({ nx, ny });
	}

	return 0;
}