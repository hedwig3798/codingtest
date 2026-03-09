#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using ll = long long;

#define MAX_CITY 1'001
#define MAX_DELAY 100

int N, M, K;

std::vector<std::pair<int, int>> cities[MAX_CITY];
std::vector<int> ans[MAX_CITY];

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> M >> K;

	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		std::cin >> a >> b >> c;

		cities[a].push_back({ b, c });
	}

	std::priority_queue<std::pair<int, int>> pq;
	pq.push({ 0, 1 });

	while (false == pq.empty())
	{
		const auto& curr = pq.top();
		int cCost = -curr.first;
		int cNode = curr.second;
		pq.pop();

		if (K <= ans[cNode].size())
		{
			continue;
		}

		ans[cNode].push_back(cCost);

		for(const auto& next : cities[cNode])
		{
			int nNode = next.first;
			int nCost = next.second + cCost;

			pq.push({ -nCost, nNode });
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		if (K != ans[i].size())
		{
			std::cout << -1 << '\n';
		}
		else
		{
			std::cout << ans[i].back() << '\n';
		}
	}

	return 0;
}