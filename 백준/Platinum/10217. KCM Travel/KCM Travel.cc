#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

#define MAX_COUNT 101
#define MAX_COST 10'001

int T, N, M, K;

struct State
{
	int time, cost, node;

	bool operator>(const State& other) const
	{
		return time > other.time;
	}
};

std::vector<State> airport[MAX_COUNT];
int dp[MAX_COUNT][MAX_COST];

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> T >> N >> M >> K;

	for (int i = 0; i < K; i++)
	{
		int u, v, c, d;
		std::cin >> u >> v >> c >> d;
		airport[u].push_back({ d,c,v });
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			dp[i][j] = INT_MAX;
		}
	}

	dp[1][0] = 0;
	for (int c = 0; c <= M; c++)
	{
		for (int u = 1; u <= N; u++)
		{
			if (dp[u][c] == INT_MAX)
			{
				continue;
			}

			for (auto& edge : airport[u]) 
			{
				int nTime = dp[u][c] + edge.time;
				int nCost = c + edge.cost;
				int nNode = edge.node;

				if (nCost <= M && dp[nNode][nCost] > nTime) 
				{
					dp[nNode][nCost] = nTime;
				}
			}
		}
	}

	int ans = INT_MAX;
	for (int i = 1; i <= M; i++)
	{
		ans = std::min(ans, dp[N][i]);
	}

	if (INT_MAX == ans)
	{
		std::cout << "Poor KCM";
	}
	else
	{
		std::cout << ans;
	}

	return 0;
}