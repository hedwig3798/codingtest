#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

#define MAX_N 8

int N, M;
int office[MAX_N][MAX_N] = { 0, };
int see[MAX_N][MAX_N] = { 0, };

struct Camera
{
	int m_x;
	int m_y;
	int m_type;
};
std::vector<Camera> camera;

int ans = INT_MAX;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void AddSee(int _x, int _y, int _dir, int _val)
{
	while (true)
	{
		int nx = _x + dx[_dir];
		int ny = _y + dy[_dir];

		if (nx < 0
			|| ny < 0
			|| nx >= N
			|| ny >= M
			|| 6 == office[nx][ny])
		{
			break;
		}

		see[nx][ny] += _val;
		_x = nx;
		_y = ny;
	}
}

int DFS(int _curr)
{
	if (_curr == camera.size())
	{
		int res = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (0 == see[i][j]
					&& 0 == office[i][j])
				{
					res++;
				}
			}
		}
		return res;
	}

	const Camera& c = camera[_curr];

	if (1 == c.m_type)
	{
		int cx = c.m_x;
		int cy = c.m_y;

		int res = INT_MAX;
		for (int i = 0; i < 4; ++i)
		{
			AddSee(cx, cy, i, 1);
			res = std::min(res, DFS(_curr + 1));
			AddSee(cx, cy, i, -1);
		}
		return res;
	}
	else if (2 == c.m_type)
	{
		int cx = c.m_x;
		int cy = c.m_y;

		int res = INT_MAX;
		for (int i = 0; i < 2; ++i)
		{
			AddSee(cx, cy, i, 1);
			AddSee(cx, cy, i + 2, 1);
			res = std::min(res, DFS(_curr + 1));
			AddSee(cx, cy, i, -1);
			AddSee(cx, cy, i + 2, -1);
		}
		return res;
	}
	else if (3 == c.m_type)
	{
		int cx = c.m_x;
		int cy = c.m_y;

		int res = INT_MAX;
		for (int i = 0; i < 4; ++i)
		{
			AddSee(cx, cy, i, 1);
			AddSee(cx, cy, (i + 1) % 4, 1);
			res = std::min(res, DFS(_curr + 1));
			AddSee(cx, cy, i, -1);
			AddSee(cx, cy, (i + 1) % 4, -1);
		}
		return res;
	}
	else if (4 == c.m_type)
	{
		int cx = c.m_x;
		int cy = c.m_y;

		int res = INT_MAX;
		for (int i = 0; i < 4; ++i)
		{
			AddSee(cx, cy, (i + 1) % 4, 1);
			AddSee(cx, cy, (i + 2) % 4, 1);
			AddSee(cx, cy, (i + 3) % 4, 1);
			res = std::min(res, DFS(_curr + 1));
			AddSee(cx, cy, (i + 1) % 4, -1);
			AddSee(cx, cy, (i + 2) % 4, -1);
			AddSee(cx, cy, (i + 3) % 4, -1);
		}
		return res;
	}
	else if (5 == c.m_type)
	{
		int cx = c.m_x;
		int cy = c.m_y;

		int res = INT_MAX;
		AddSee(cx, cy, 0, 1);
		AddSee(cx, cy, 1, 1);
		AddSee(cx, cy, 2, 1);
		AddSee(cx, cy, 3, 1);
		res = std::min(res, DFS(_curr + 1));
		AddSee(cx, cy, 0, -1);
		AddSee(cx, cy, 1, -1);
		AddSee(cx, cy, 2, -1);
		AddSee(cx, cy, 3, -1);
		return res;
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::cin >> office[i][j];
			if (5 >= office[i][j]
				&& 1 <= office[i][j])
			{
				camera.push_back({ i, j, office[i][j] });
			}
		}
	}

	std::cout << DFS(0);

	return 0;
}