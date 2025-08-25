#include <bits/stdc++.h>
#include <unordered_set>

#define le9 1'000'000'001
#define MOD 1'000'003

typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::pair<ll, ll> pll;


int N, M;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> M;
	std::vector<std::vector<int>> graph(N + 1, std::vector<int>(N + 1, le9));

	for (int i = 0; i < M; i++)
	{
		int t, f;
		std::cin >> t >> f;
		graph[t][f] = 1;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j)
				{
					continue;
				}

				graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	std::vector<int> count(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (graph[i][j] != le9)
			{
				++count[i];
				++count[j];
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		std::cout << N - count[i] - 1 << '\n';
	}

	return 0;
}