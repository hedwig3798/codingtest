#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

#define MAX_N 80
#define MAX_COUNT 80 * 80

int C, N, M;
std::string classroom[80];

std::vector<int> graph[MAX_COUNT];
int left[MAX_COUNT];
int right[MAX_COUNT];
bool checked[MAX_COUNT];

bool Linked(int _curr)
{
	for (const auto& next : graph[_curr])
	{
		if (true == checked[next])
		{
			continue;
		}

		checked[next] = true;

		if (-1 == right[next] || Linked(right[next]))
		{
			left[_curr] = next;
			right[next] = _curr;
			return true;
		}
	}

	return false;
}

int dx[] = { -1, 0, 1, -1, 0, 1 };
int dy[] = { -1, -1, -1, 1, 1, 1 };

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> C;

	for (int tc = 0; tc < C; ++tc)
	{
		std::cin >> N >> M;

		for (int i = 0; i < MAX_COUNT; ++i)
		{
			graph[i].clear();
		}
		for (int i = 0; i < N; ++i)
		{
			std::cin >> classroom[i];
		}

		int allDesk = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if ('.' == classroom[i][j])
				{
					allDesk++;
					for (int k = 0; k < 6; ++k)
					{
						int nx = i + dx[k];
						int ny = j + dy[k];

						if (nx < 0
							|| nx >= N
							|| ny < 0
							|| ny >= M
							|| 'x' == classroom[nx][ny])
						{
							continue;
						}

						graph[i * M + j].push_back(nx * M + ny);
					}
				}

			}
		}

		int count = 0;
		std::fill(left, left + MAX_COUNT, -1);
		std::fill(right, right + MAX_COUNT, -1);
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; j += 2)
			{
				if ('.' == classroom[i][j])
				{
					std::fill(checked, checked + MAX_COUNT, false);
					if (Linked(i * M + j))
					{
						count++;
					}
				}

			}
		}
		std::cout << allDesk - count << '\n';
	}


	return 0;
}