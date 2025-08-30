#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;

int V, E;
int road[401][401] = { 0, };

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> V >> E;

	for (int i = 0; i <= V ; i++)
	{
		for (int j = 0; j <= V ; j++)
		{
			road[i][j] = le9;
		}
	}

	for (int i = 0; i < E; i++)
	{
		int to, from, cost;
		std::cin >> to >> from >> cost;
		road[to][from] = cost;
	}

	for (int k = 1; k <= V ; k++)
	{
		for (int i = 1; i <= V ; i++)
		{
			for (int j = 1; j <= V ; j++)
			{
				if (i == j)
				{
					continue;
				}

				road[i][j] = std::min(road[i][j], road[i][k] + road[k][j]);
			}
		}
	}

	int ans = le9;

	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (i == j)
			{
				continue;
			}

			ans = std::min(ans, road[i][j] + road[j][i]);
		}
	}

	if (le9 == ans)
	{
		std::cout << -1;
	}
	else
	{
		std::cout << ans;
	}
	return 0;
}