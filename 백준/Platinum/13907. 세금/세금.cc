#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

#define MAX_NODE 1'001
#define MAX_ROAD 30'001

int N, M, K, S, D;
std::vector<std::pair<int, int>> road[MAX_NODE];
int distance[MAX_NODE][MAX_NODE] = { 0, };

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> M >> K >> S >> D;

	for (int i = 0; i < MAX_NODE; ++i)
	{
		for (int j = 0; j < MAX_NODE; ++j)
		{
			distance[i][j] = INT_MAX;
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		road[a].push_back({ b, c });
		road[b].push_back({ a, c });
	}

	std::priority_queue<std::vector<int>> pq;
	pq.push({ 0, S, 0 });

	while (false == pq.empty())
	{
		const auto& curr = pq.top();
		int cCost = -curr[0];
		int cNode = curr[1];
		int cCount = curr[2];
		pq.pop();

		for (const auto& next : road[cNode])
		{
			int nNode = next.first;
			int nCost = next.second + cCost;
			int nCount = cCount + 1;

			if (distance[nNode][nCount] > nCost)
			{
				bool possible = true;
				for (int i = 1; i < nCount; i++)
				{
					if (distance[nNode][i] <= nCost)
					{
						possible = false;
						break;
					}
				}

				if (true == possible)
				{
					distance[nNode][nCount] = nCost;
					pq.push({ -nCost, nNode, nCount });
				}
			}
		}
	}


	int rise = 0;
	for (int i = 0; i <= K; ++i)
	{
		int p;
		if (0 == i)
		{
			p = 0;
		}
		else
		{
			std::cin >> p;
		}

		rise += p;
		int ans = INT_MAX;
		for (int j = 1; j < N; ++j)
		{
			if (INT_MAX == distance[D][j])
			{
				continue;
			}
			ans = std::min(ans, distance[D][j] + j * rise);
		}
		std::cout << ans << '\n';
	}

	return 0;
}