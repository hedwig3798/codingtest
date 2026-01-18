#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

int n, m;

std::vector<std::vector<std::pair<int, int>>> cities;
std::vector<std::vector<std::pair<int, int>>> reversCities;
std::vector<int> indegree;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> n >> m;

	cities.resize(n + 1);
	reversCities.resize(n + 1);
	indegree.resize(n + 1, 0);

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		std::cin >> u >> v >> w;
		cities[u].push_back({ v, w });
		reversCities[v].push_back({ u, w });
		indegree[v]++;
	}

	int han, roma;
	std::cin >> han >> roma;

	std::queue<std::pair<int, int>> pq;
	std::vector<int> costs(n + 1, 0);

	costs[han] = 0;
	pq.push({ han, 0 });

	while (false == pq.empty())
	{
		auto& curr = pq.front();

		int cNode = curr.first;
		int cCost = curr.second;

		pq.pop();

		for (auto& next : cities[cNode])
		{
			int nNode = next.first;
			int nCost = next.second;

			costs[nNode] = std::max(costs[nNode], nCost + cCost);
			indegree[nNode]--;
			if (0 == indegree[nNode])
			{
				pq.push({ nNode, costs[nNode] });
			}
		}
	}

	std::cout << costs[roma] << '\n';

	int ans = 0;
	std::queue<int> q;
	std::vector<bool> isVisit(n + 1, false);
	q.push(roma);

	while (false == q.empty())
	{
		int curr = q.front();
		q.pop();

		for(auto& next : reversCities[curr])
		{
			int nNode = next.first;
			int nCost = next.second;
			if (costs[next.first] == costs[curr] - nCost)
			{
				ans++;
				if (false == isVisit[nNode])
				{
					isVisit[nNode] = true;
					q.push(nNode);
				}
			}
		}
	}
	std::cout << ans;

	return 0;
}