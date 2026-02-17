#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

#define MAX_NUM 100'001
#define LOG 18

int N, K;

int depth[MAX_NUM] = { 0, };
int parent[MAX_NUM][LOG] = { 0, };
int minRoad[MAX_NUM][LOG] = { 0, };
int maxRoad[MAX_NUM][LOG] = { 0, };
std::vector<std::pair<int, int>> roads[MAX_NUM];

void SetTree(int _par)
{
	for (auto& next : roads[_par])
	{
		if (0 == depth[next.first])
		{
			depth[next.first] = depth[_par] + 1;
			minRoad[next.first][0] = next.second;
			maxRoad[next.first][0] = next.second;
			parent[next.first][0] = _par;
			SetTree(next.first);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;

	for (int i = 0; i < N - 1; ++i)
	{
		int A, B, C;
		std::cin >> A >> B >> C;
		roads[A].push_back({ B,C });
		roads[B].push_back({ A,C });
	}

	for (int i = 0; i < MAX_NUM; i++) 
	{
		for (int j = 0; j < LOG; j++)
		{
			minRoad[i][j] = INT_MAX;
		}
	}

	depth[1] = 1;
	SetTree(1);

	for (int i = 1; i < LOG; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
			minRoad[j][i] = std::min(minRoad[j][i - 1], minRoad[parent[j][i - 1]][i - 1]);
			maxRoad[j][i] = std::max(maxRoad[j][i - 1], maxRoad[parent[j][i - 1]][i - 1]);
		}
	}

	std::cin >> K;
	for (int i = 0; i < K; ++i)
	{
		int minRes = INT_MAX;
		int maxRes = 0;
		int D, E;
		std::cin >> D >> E;

		if (depth[D] < depth[E])
		{
			std::swap(D, E);
		}

		for (int k = LOG - 1; k >= 0; --k)
		{
			if (depth[D] - (1 << k) >= depth[E])
			{
				minRes = std::min(minRes, minRoad[D][k]);
				maxRes = std::max(maxRes, maxRoad[D][k]);
				D = parent[D][k];
			}
		}

		if (D == E)
		{
			std::cout << minRes << ' ' << maxRes << '\n';
			continue;
		}

		for (int k = LOG - 1; k >= 0; --k)
		{
			if (parent[D][k] != parent[E][k])
			{
				minRes = std::min(minRes, minRoad[D][k]);
				maxRes = std::max(maxRes, maxRoad[D][k]);				

				minRes = std::min(minRes, minRoad[E][k]);
				maxRes = std::max(maxRes, maxRoad[E][k]);
				D = parent[D][k];
				E = parent[E][k];
			}
		}

		minRes = std::min(minRes, minRoad[D][0]);
		maxRes = std::max(maxRes, maxRoad[D][0]);

		minRes = std::min(minRes, minRoad[E][0]);
		maxRes = std::max(maxRes, maxRoad[E][0]);

		std::cout << minRes << ' ' << maxRes << '\n';
	}

	return 0;
}