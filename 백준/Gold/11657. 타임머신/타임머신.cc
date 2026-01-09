#include <bits/stdc++.h>
#include <unordered_set>

int N, M;

std::vector<std::vector<int>> edges;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		std::cin >> A >> B >> C;
		edges.push_back({ A, B, C });
	}

	std::vector<long long> ans(N + 1, INT_MAX);
	ans[1] = 0;

	for (int i = 0; i < M; i++)
	{
		for (auto& itr : edges)
		{
			int A = itr[0];
			int B = itr[1];
			int C = itr[2];

			if (INT_MAX == ans[A])
			{
				continue;
			}

			ans[B] = std::min(ans[B], ans[A] + C);
		}
	}

	std::vector<bool> check(N + 1, true);
	for (auto& itr : edges)
	{
		int A = itr[0];
		int B = itr[1];
		int C = itr[2];

		if (INT_MAX == ans[A])
		{
			continue;
		}
		if (ans[B] > ans[A] + C)
		{
			std::cout << -1 << '\n';
			return 0;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (false == check[i]
			|| ans[i] == INT_MAX)
		{
			std::cout << -1 << '\n';
		}
		else
		{
			std::cout << ans[i] << '\n';
		}
	}

	return 0;
}