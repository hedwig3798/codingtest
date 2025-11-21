#include <bits/stdc++.h>
#include <unordered_set>

int N;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::cin >> N;

	std::vector<unsigned long long> length(N - 1);
	std::vector<unsigned long long> cost(N);

	for (int i = 0; i < N - 1; ++i)
	{
		std::cin >> length[i];
	}

	for (int i = 0; i < N ; ++i)
	{
		std::cin >> cost[i];
	}

	unsigned long long minCost = cost[0];
	unsigned long long ans = 0;
	for (int i = 0; i < N - 1; ++i)
	{
		minCost = std::min(minCost, cost[i]);
		ans += minCost * length[i];
	}

	std::cout << ans;

	return 0;
}