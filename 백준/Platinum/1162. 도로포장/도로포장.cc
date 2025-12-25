#include <bits/stdc++.h>
#include <unordered_set>

const long long INF = 1e16;

int N, M, K;

long long dp[10'001][21] = {};

std::vector<std::vector<std::pair<int, int>>> cost;
int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> M >> K;

	for (int i = 0; i <= N; i++) 
	{
		for (int j = 0; j <= K; j++)
		{
			dp[i][j] = INF;
		}
	}

	cost.resize(N + 1);
	for (int i = 0; i < M ; i++)
	{
		long long a, b, c;
		std::cin >> a >> b >> c;

		cost[a].push_back({ b, c });
		cost[b].push_back({ a, c });
	}

	std::priority_queue<std::vector<long long>> pq;
	pq.push({ 0, 1, K });
	dp[1][K] = 0;

	while (false == pq.empty())
	{
		std::vector<long long> curr = pq.top();
		pq.pop();

		long long cCost = -curr[0];
		long long cNode = curr[1];
		long long cLeft = curr[2];

		if (cCost > dp[cNode][cLeft])
		{
			continue;
		}

		for(auto& next : cost[cNode])
		{
			long long nNode = next.first;
			long long nCost = next.second;

			if (0 < cLeft && dp[nNode][cLeft - 1] > cCost)
			{
				dp[nNode][cLeft - 1] = cCost;
				pq.push({ -cCost, nNode, cLeft - 1 });
			}

			if (dp[nNode][cLeft] > nCost + cCost)
			{
				dp[nNode][cLeft] = nCost + cCost;
				pq.push({ -(nCost + cCost), nNode, cLeft});
			}
		}
	}

	long long ans = INF;
	for (int i = 0; i <= K ; i++)
	{
		ans = std::min(ans, dp[N][i]);
	}

	std::cout << ans;

	return 0;
}